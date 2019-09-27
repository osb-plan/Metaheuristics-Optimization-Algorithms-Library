/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Individuals_impl.h
 * Author: utente
 *
 * Created on July 28, 2019, 12:08 AM
 */

#ifndef INDIVIDUALS_IMPL_H
#define INDIVIDUALS_IMPL_H


#include "../include/Individuals.h"

 
    template<class T> inline Individuals<T>::Individuals(std::vector<T> pos, double fit) :
        _positions(pos),
        _fitness(fit)    
    {

    }; 



#endif /* INDIVIDUALS_IMPL_H */

