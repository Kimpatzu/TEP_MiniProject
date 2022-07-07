cmake_minimum_required(VERSION 3.20)
project(TEPLab_MiniProjekt_v2)

set(CMAKE_CXX_STANDARD 14)

add_executable(TEPLab_MiniProjekt_v2 main.cpp Clause.cpp Clause.h CGAIndividual.cpp CGAIndividual.h CGAOptimizer.cpp CGAOptimizer.h CMAX3SatProblem.cpp CMAX3SatProblem.h)
