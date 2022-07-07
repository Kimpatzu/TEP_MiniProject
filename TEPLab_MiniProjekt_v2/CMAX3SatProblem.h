#ifndef TEPLAB_MINIPROJEKT_V2_CMAX3SATPROBLEM_H
#define TEPLAB_MINIPROJEKT_V2_CMAX3SATPROBLEM_H
#include <iostream>
#include "vector"
#include "CGAOptimizer.h"
#include "Clause.h"
#include "fstream"
#include "string"


class CMAX3SatProblem {
public:
    CMAX3SatProblem(std::string sSourcePath, CGAOptimizer &cgaOptim, int iNumberOfGenerations);
    ~CMAX3SatProblem();

    void Load(std::string &sPath);
    void vVariableNumberChecker(std::string &sPath);
    void Compute(std::vector<CGAIndividual*> vbGenotype);
    void vPrintChampion();
    void run();

private:
    int iNumberOfGenerations;
    int iNumberOfVar;
    std::string sSourcePath;
    std::vector<Clause*> vClauses;
    CGAOptimizer cgaOptimizer;
    CGAIndividual *champion;
};


#endif //TEPLAB_MINIPROJEKT_V2_CMAX3SATPROBLEM_H
