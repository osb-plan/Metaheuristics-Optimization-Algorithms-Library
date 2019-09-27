/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FitnessChecker.cpp
 * Author: utente
 * 
 * Created on June 30, 2019, 10:56 PM
 */

#include "../include/FitnessChecker.h"
#include "../include/fitness_functions_defs.h"
#include <array>

extern const std::array<std::string, FITNESS_FUNCTIONS_NAMES::fitCOUNT> fitness_labels;


FitnessChecker::FitnessChecker() {
}



FitnessChecker::~FitnessChecker() {
}

bool FitnessChecker::Run(std::string str) const{
    for(int cnt = 0; cnt < FITNESS_FUNCTIONS_NAMES::fitCOUNT; cnt++)
    {
        if(!fitness_labels.at(cnt).compare(str))
            return true;
    }
    return false;
}