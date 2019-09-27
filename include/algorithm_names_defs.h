/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   algorithm_names_defs.h
 * Author: utente
 *
 * Created on June 27, 2019, 9:38 PM
 */

#ifndef ALGORITHM_NAMES_DEFS_H
#define ALGORITHM_NAMES_DEFS_H

#include <array>
#include <string>

#ifdef __cplusplus
extern "C" {
#endif

    typedef enum{
        PSO = 0,
        FSO = 1,
        GA  = 2,
        FIREF = 3,
        ANT = 4,
        BEE = 5,
        algCOUNT = 6
    } ALGORITHMS_NAMES;

    const std::array<std::string, 6> algorithms_labels 
    {{
        "PSO",
        "FSO",
        "GA",
        "FIREF",
        "ANT",
        "BEE"                
    }};

#ifdef __cplusplus
}
#endif

#endif /* ALGORITHM_NAMES_DEFS_H */

