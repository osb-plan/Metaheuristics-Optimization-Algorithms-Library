/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlgorithmChecker.cpp
 * Author: utente
 * 
 * Created on June 30, 2019, 10:27 PM
 */

#include "../include/AlgorithmChecker.h"
#include "../include/algorithm_names_defs.h"
#include "../include/fitness_functions_defs.h"
#include "../include/GeneticAlgorithm.h"
#include "../include/architecture.h"

extern const std::array<std::string, FITNESS_FUNCTIONS_NAMES::fitCOUNT> fitness_labels ;

extern const std::array<std::string, ALGORITHMS_NAMES::algCOUNT> algorithms_labels; 

AlgorithmChecker::AlgorithmChecker() {
}



bool AlgorithmChecker::Run(std::string str) const{
    for(int cnt = 0; cnt < ALGORITHMS_NAMES::algCOUNT; cnt++)
    {
        if(!algorithms_labels.at(cnt).compare(str))
            return true;
    }
    return false;
}


unsigned int AlgorithmChecker::getAlgorithmEnum(std::string str)
{
    for(int cnt = 0; cnt < ALGORITHMS_NAMES::algCOUNT; cnt++)
    {
        if(!algorithms_labels.at(cnt).compare(str))
            return cnt;
    }
    return 0;    
}

unsigned int AlgorithmChecker::getFitnessEnum(std::string str)
{
    for(int cnt = 0; cnt < FITNESS_FUNCTIONS_NAMES::fitCOUNT; cnt++)
    {
        if(!fitness_labels.at(cnt).compare(str))
            return cnt;
    }
    return 0;    
}

void AlgorithmChecker::MainRun(std::string str, std::string ftmng_str)
{
    unsigned int algName = getAlgorithmEnum(str);
    FitnessFunctionMgmt ftmng;
    
    ftmng.SetFitness_function((FITNESS_FUNCTIONS_NAMES)getFitnessEnum(ftmng_str));
    GeneticAlgorithm *algGA = nullptr;
    switch(algName)
    {
        case(PSO):
            std::cout << "We run Algorithm PSO" << std::endl;
            break;
        case(FSO):
            std::cout << "We run Algorithm FSO" << std::endl;
            break;              
        case(GA):
            algGA = new GeneticAlgorithm(
                                        true,
                                        10,
                                        100,
                                        2,
                                        ftmng);
            std::cout << "We run Algorithm GA" << std::endl;
            algGA->Init();
            algGA->Run();
            break;            
        case(FIREF):
            std::cout << "We run Algorithm FIREF" << std::endl;
            break; 
        case(ANT):
            std::cout << "We run Algorithm ANT" << std::endl;
            break;            
        default:
            std::cout << "Algorithm not recognized!" << std::endl;
            break;
    }
}
