/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newfile.h
 * Author: utente
 *
 * Created on June 27, 2019, 9:42 PM
 */

#ifndef NEWFILE_H
#define NEWFILE_H

#include <array>
#include <string>

#ifdef __cplusplus
extern "C" {
#endif



    typedef enum{
        ACKLEY = 0,
        LEVY   = 1,
        CUSTOM = 2,
        fitCOUNT = 3
    } FITNESS_FUNCTIONS_NAMES;
    
    const std::array<std::string, FITNESS_FUNCTIONS_NAMES::fitCOUNT> fitness_labels 
    {
        "ACKLEY",
        "LEVY"
    };


#ifdef __cplusplus
}
#endif

#endif /* NEWFILE_H */

