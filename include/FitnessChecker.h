/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FitnessChecker.h
 * Author: utente
 *
 * Created on June 30, 2019, 10:56 PM
 */

#ifndef FITNESSCHECKER_H
#define FITNESSCHECKER_H

#include <string>
#include "../include/Checker.h"

class FitnessChecker : public Checker{
public:
    FitnessChecker();

    virtual ~FitnessChecker();
    bool Run(std::string str) const;
private:

};

#endif /* FITNESSCHECKER_H */

