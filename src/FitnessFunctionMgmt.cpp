/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FitnessFunctionMgmt.cpp
 * Author: utente
 * 
 * Created on July 5, 2019, 11:06 AM
 */

#include "../include/FitnessFunctionMgmt.h"
#include <vector>
#include <iostream>


FitnessFunctionMgmt::FitnessFunctionMgmt() {
}

/*FitnessFunctionMgmt::~FitnessFunctionMgmt_INT() {
}*/

void FitnessFunctionMgmt::CalculateFitness(Individuals<_ARCH>& ind)
{
    float res;
    std::vector<_ARCH> pos = ind.GetPositions();
    switch(this->_fitness_function)
    {
        case(ACKLEY):
            {
                res = pos.at(0) + pos.at(1) - 1.5; //just for example            
            }
            break;
        case(LEVY):
            {
                res = pos.at(0)*2 + pos.at(1); //just for example
            }    
            break;            
         
        case(CUSTOM):
            {
                res = pos.at(0)*2 + pos.at(1) - 2; //just for example
            }
            break;                       
        default:
            {
                res = 0;
                std::cout << "Attention default calculation in fitness function" << std::endl;
            }
            break;                                   
    }
    ind.SetFitness(res);
}
