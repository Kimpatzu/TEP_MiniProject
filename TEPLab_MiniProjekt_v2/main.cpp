#include <iostream>
#include "CGAOptimizer.h"
#include "CGAIndividual.h"
#include "CMAX3SatProblem.h"
#include "Clause.h"



int main() {
    std::string spath = "m3s";
    CGAOptimizer myoptim = CGAOptimizer(20,30,30);
    CMAX3SatProblem CM3S = CMAX3SatProblem("m3s_50_1.txt",myoptim,10);
    CM3S.run();
    return 0;
}
