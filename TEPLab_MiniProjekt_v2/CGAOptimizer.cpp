#include "CGAOptimizer.h"

CGAOptimizer::CGAOptimizer() {
    this->iPopulationSize = DEFAULT_POPULATION_SIZE;
    this->iCrossoverProbability = DEFAULT_CROSSOVER_PROBABILITY;
    this->iMutationProbability = DEFAULT_MUTATION_PROBABILITY;
}

CGAOptimizer::CGAOptimizer(int iPopulationSize, int iCrossoverProbability, int iMutationProbability) {
    if(iPopulationSize<20){
        this->iPopulationSize = DEFAULT_POPULATION_SIZE;
    } else {
        this->iPopulationSize=iPopulationSize;
    }
    if(iCrossoverProbability<0 || iCrossoverProbability>100){
        this->iCrossoverProbability = DEFAULT_CROSSOVER_PROBABILITY;
    } else {
        this->iCrossoverProbability=iCrossoverProbability;
    }
    if(iMutationProbability<0 || iMutationProbability>100){
        this->iMutationProbability = DEFAULT_MUTATION_PROBABILITY;
    } else {
        this->iMutationProbability=iMutationProbability;
    }
}

CGAOptimizer::~CGAOptimizer() {
    for(int i=0; i<population.size(); i++){
        population.clear();
    }
}

void CGAOptimizer::Initialize(int iNumberOfVariables) {
    for (int i=0; i<iPopulationSize; i++){
        population.push_back(new CGAIndividual(iNumberOfVariables));
    }
}

const  std::vector<CGAIndividual*> CGAOptimizer::getPopulation() const {
    return population;
}

void CGAOptimizer::RunIteration() {
    std::vector<CGAIndividual*> newPopulation;
    while(newPopulation.size()<getPopulation().size()){
        CGAIndividual *parent1 = chooseParent(getPopulation());
        CGAIndividual *parent2 = chooseParent(getPopulation());
        CGAIndividual *child1 = new CGAIndividual(1);
        CGAIndividual *child2 = new CGAIndividual(1);
        child1->Crossover(*parent1, *parent2);
        child2->vMirrorFirstChild(*child1);
        child1->Mutation(iMutationProbability);
        child2->Mutation(iMutationProbability);
        newPopulation.push_back(child1);
        newPopulation.push_back(child2);
    }
    population.clear();
    population = newPopulation;
}

CGAIndividual* CGAOptimizer::chooseParent(std::vector<CGAIndividual *> population) {
    int random;
    srand((unsigned int) time(nullptr));
    random = rand() % population.size();
    CGAIndividual *contender1 = population.at(random);
    srand((unsigned int) time(nullptr));
    random = rand() % population.size();
    CGAIndividual *contender2 = population.at(random);
    if (contender1->Fitness() >= contender2->Fitness()){
        return contender1;
    } else {
        return contender2;
    }
}