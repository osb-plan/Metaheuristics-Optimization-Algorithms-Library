/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ShellParameters.h
 * Author: utente
 *
 * Created on June 27, 2019, 8:39 PM
 */

#ifndef SHELLPARAMETERS_H
#define SHELLPARAMETERS_H

#include <string>

class ShellParameters {
public:
    ShellParameters();
    virtual ~ShellParameters();
    
    std::string GetAlgorithmName() const {
        return _algorithmName;
    }

    void SetAlgorithmName(std::string _algorithmName) {
        this->_algorithmName = _algorithmName;
    }

    std::string GetFitnessFunction() const {
        return _fitnessFunction;
    }

    void SetFitnessFunction(std::string _fitnessFunction) {
        this->_fitnessFunction = _fitnessFunction;
    }

private:
    std::string _algorithmName;
    std::string _fitnessFunction;
    
    
};

#endif /* SHELLPARAMETERS_H */

