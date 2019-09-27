/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Checker.h
 * Author: utente
 *
 * Created on June 30, 2019, 10:25 PM
 */

#ifndef CHECKER_H
#define CHECKER_H

#include <string>

class Checker {
public:
    Checker();
    virtual ~Checker();
    
    virtual bool Run(std::string str) const = 0;
    
private:

};

#endif /* CHECKER_H */

