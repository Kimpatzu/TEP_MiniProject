#include "CMAX3SatProblem.h"
#include <iostream>

CMAX3SatProblem::CMAX3SatProblem(std::string sSourcePath,CGAOptimizer &cgaOptim,int iNumberOfGenerations) {
    this->iNumberOfGenerations = iNumberOfGenerations;
    this->sSourcePath = sSourcePath;
    this->cgaOptimizer = cgaOptim;
    vVariableNumberChecker(sSourcePath);
    Load(this->sSourcePath);
}

CMAX3SatProblem::~CMAX3SatProblem() {
    vClauses.clear();
}

void CMAX3SatProblem::Load(std::string &sPath) {
    vClauses.clear();
    std::string sCurrentLine;
    std::ifstream ifstrSource ("m3s_50_0.txt");
 //   ifstrSource.open(sPath,std::ios::in);
    while(std::getline(ifstrSource, sCurrentLine)){
        if(sCurrentLine != "") {
            vClauses.push_back(new Clause(sCurrentLine));
        }
    }
    ifstrSource.close();
    cgaOptimizer.Initialize(iNumberOfVar);
    champion = cgaOptimizer.getPopulation().at(0);
    ifstrSource.close();
}

void CMAX3SatProblem::vVariableNumberChecker(std::string &sPath) {
    std::ifstream ifstrSource (sPath);
    std::string sCurrentLine = "";
    if (ifstrSource.is_open()){
        int max=0;
        while(std::getline(ifstrSource, sCurrentLine)){
            sCurrentLine = sCurrentLine.substr(2, sCurrentLine.length()-3);
            int iCurrent=0;
            std::string sCurrentString = "";
            bool firstWhiteSpace = true;
            for(int i=0; i<sCurrentLine.length(); i++){
                if (sCurrentLine.at(i) != ' '){
                    sCurrentString += sCurrentLine.at(i);
                    firstWhiteSpace = true;
                } else {
                    if (firstWhiteSpace && sCurrentString != ""){
                        iCurrent = std::stoi(sCurrentString);
                        sCurrentString = "";
                        if(iCurrent < 0 && -iCurrent>max){
                            max = -iCurrent;
                        } if(iCurrent>=0 && iCurrent>max){
                            max = iCurrent;
                        }
                    }
                }
            }
        }
        iNumberOfVar = max + 1; //dla 50 zmiennych max dawałby 49, bo zaczynają się one od 0
    }
}

void CMAX3SatProblem::Compute(std::vector<CGAIndividual*> vPopulation) {
    cgaOptimizer.RunIteration();
    std::vector<CGAIndividual*> currPopulation= vPopulation;
    for (int i=0; i < currPopulation.size(); i++){
        int iPleasedCount = 0;
        double dCurrentFitness = 0.0;
        for (int j=0; j<vClauses.size(); j++){
            if(vClauses.at(j)->isPleased(currPopulation.at(i)->getGenotype())){
                iPleasedCount++;
            }
        }
        dCurrentFitness = (double)iPleasedCount/(double)vClauses.size();
        currPopulation.at(i)->vSetFitness(dCurrentFitness);
    }
    for (int i=0; i < currPopulation.size(); i++) {
        if(currPopulation.at(i)->Fitness() > champion->Fitness()){
            champion = currPopulation.at(i);
        }
    }

}

void CMAX3SatProblem::vPrintChampion() {
    champion->vPrint();
}

void CMAX3SatProblem::run() {
    for (int i=0; i<iNumberOfGenerations; i++){
        Compute(cgaOptimizer.getPopulation());
    }
    vPrintChampion();
}