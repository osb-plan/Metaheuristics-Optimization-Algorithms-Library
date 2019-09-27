/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Algorithm.h
 * Author: utente
 *
 * Created on August 19, 2019, 9:08 PM
 */

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "../include/algorithm_names_defs.h"

class  Algorithm {
public:
    Algorithm();
    virtual ~Algorithm();
    virtual bool Init() = 0;
    virtual void Run() = 0;
    unsigned int error = 0;
private:

};

#endif /* ALGORITHM_H */

