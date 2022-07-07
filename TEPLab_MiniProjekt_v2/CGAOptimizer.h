#ifndef TEPLAB_MINIPROJEKT_V2_CGAOPTIMIZER_H
#define TEPLAB_MINIPROJEKT_V2_CGAOPTIMIZER_H
#include "CGAIndividual.h"
#include <iostream>
#include "vector"
#define DEFAULT_POPULATION_SIZE 20
#define DEFAULT_CROSSOVER_PROBABILITY 30
#define DEFAULT_MUTATION_PROBABILITY 30

class CGAOptimizer {

public:
    CGAOptimizer();
    CGAOptimizer(int iPopulationSize, int iCrossoverProbability, int iMutationProbability);
    ~CGAOptimizer();

    void Initialize(int INumberOfVariables);
    const  std::vector<CGAIndividual*> getPopulation() const;
    void RunIteration();
private:
    int iPopulationSize;
    int iCrossoverProbability;
    int iMutationProbability;
    std::vector<CGAIndividual*> population;

    CGAIndividual *chooseParent(std::vector<CGAIndividual*> population);
};


#endif //TEPLAB_MINIPROJEKT_V2_CGAOPTIMIZER_H
