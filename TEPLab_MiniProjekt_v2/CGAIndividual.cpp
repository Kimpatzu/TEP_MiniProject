#include "CGAIndividual.h"


CGAIndividual::CGAIndividual(int iNumberOfVariables) {
    dFitness = 0.0;
    if (iNumberOfVariables <=0 ){
        std::cout<<"CGAIndividual constructor - iNumberOfVariables less/eq than zero"<<std::endl;
    } else {
        int random;
        srand((unsigned int) time(nullptr));
        for (int i = 0; i < iNumberOfVariables; i++) {
            random = rand() % 2;
            Sleep(rand()%3);
            vbGenotype.push_back((bool) random);
        }
    }
}

CGAIndividual::~CGAIndividual() {
    vbGenotype.clear();
}

void CGAIndividual::Mutation(int iMutationChance) {
    int random;
    for (int i=0; i<vbGenotype.size(); i++){
        srand((unsigned int) time(nullptr));
        random = rand() % 100 + 1;
        if (random<=iMutationChance){
            vbGenotype.at(i)= !vbGenotype.at(i);
        }
    }
}

double CGAIndividual::Fitness() {
    return dFitness;
}

void CGAIndividual::vSetFitness(double dNewFitness) {
    dFitness = dNewFitness;
}

void CGAIndividual::Crossover(CGAIndividual &firstParent, CGAIndividual &secondParent) {
    int random;
    vbGenotype.clear();
    for(int i=0; i<firstParent.getGenotype().size(); i++){
        Sleep(1);
        random = rand() % 2;
        if(random==0){
            vbGenotype.push_back(firstParent.getGenotype().at(i));
        } else {
            vbGenotype.push_back(secondParent.getGenotype().at(i));
        }
    }
}

const std::vector<bool> &CGAIndividual::getGenotype() const {
    return vbGenotype;
}

void CGAIndividual::vPrint() {
    for (int i=0; i<vbGenotype.size(); i++){
        std::cout<<i<<": "<<vbGenotype.at(i)<<std::endl;
    }
    std::cout<<"Fitness: "<<dFitness<<std::endl;
}

void CGAIndividual::vMirrorFirstChild(CGAIndividual &firstChild) {
    vbGenotype.clear();
    for(int i=0; i<firstChild.getGenotype().size(); i++){
        vbGenotype.push_back(!firstChild.getGenotype().at(i));
    }
}
