/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlgorithmChecker.h
 * Author: utente
 *
 * Created on June 30, 2019, 10:27 PM
 */

#ifndef ALGORITHMCHECKER_H
#define ALGORITHMCHECKER_H

#include <iostream>
#include <string>

#include "Checker.h"
#include "../include/Algorithm.h"
#include "../include/FitnessFunctionMgmt.h"

class AlgorithmChecker : public Checker {
public:
    AlgorithmChecker();

    bool Run(std::string str) const;
    unsigned int getAlgorithmEnum(std::string std);
    void MainRun(std::string str, std::string ftmng);
    unsigned int getFitnessEnum(std::string str);

private:

    
};

#endif /* ALGORITHMCHECKER_H */

