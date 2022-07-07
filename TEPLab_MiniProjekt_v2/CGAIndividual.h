#ifndef TEPLAB_MINIPROJEKT_V2_CGAINDIVIDUAL_H
#define TEPLAB_MINIPROJEKT_V2_CGAINDIVIDUAL_H
#include <iostream>
#include "vector"
#include "ctime"
#include <windows.h>

class CGAIndividual {

public:
    CGAIndividual(int iNumberOfVariables);
    ~CGAIndividual();

    void vPrint();
    void Mutation(int iMutationChance);
    double Fitness();
    void vSetFitness(double dNewFitness);
    void Crossover(CGAIndividual &firstParent, CGAIndividual &secondParent);
    void vMirrorFirstChild(CGAIndividual &firstChild);
    const std::vector<bool> &getGenotype() const;

private:
    std::vector<bool> vbGenotype;
    double dFitness;
};




#endif //TEPLAB_MINIPROJEKT_V2_CGAINDIVIDUAL_H
