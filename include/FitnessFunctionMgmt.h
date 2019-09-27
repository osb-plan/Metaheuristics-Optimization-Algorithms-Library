/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FitnessFunctionMgmt.h
 * Author: utente
 *
 * Created on July 5, 2019, 11:06 AM
 */

#ifndef FITNESSFUNCTIONMGMT_H
#define FITNESSFUNCTIONMGMT_H

#include "../include/fitness_functions_defs.h"
#include "../include/Individuals.h"
#include "../include/architecture.h"

class FitnessFunctionMgmt {
public:
    FitnessFunctionMgmt();

    FITNESS_FUNCTIONS_NAMES GetFitness_function() const {
        return _fitness_function;
    }

    void SetFitness_function(FITNESS_FUNCTIONS_NAMES _fitness_function) {
        this->_fitness_function = _fitness_function;
    }

    void CalculateFitness(Individuals<_ARCH> &ind);
    
private:
    FITNESS_FUNCTIONS_NAMES _fitness_function;

};

#endif /* FITNESSFUNCTIONMGMT_H */

