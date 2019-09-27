/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Utils.cpp
 * Author: utente
 * 
 * Created on June 27, 2019, 8:26 PM
 */

// System Library
#include <getopt.h>
#include <iostream>
#include <string>
#include <array>
#include <stdint.h>
#include <vector>
#include <cmath>

// OAL
#include "../include/Utils.h"
#include "../include/ShellParameters.h"
#include "../include/algorithm_names_defs.h"
#include "../include/fitness_functions_defs.h"
#include "../include/AlgorithmChecker.h"
#include "../include/Checker.h"
#include "../include/FitnessChecker.h"

extern const std::array<std::string, FITNESS_FUNCTIONS_NAMES::fitCOUNT> fitness_labels;
extern const std::array<std::string, ALGORITHMS_NAMES::algCOUNT> algorithms_labels;

void Utils::PrintUsage()
{
    std::cout << "Usage: exec -a <algorithm_name> -f <fitness_function>" << std::endl;
    
            
}

bool CheckAlgorithmNames(std::string str)
{
    for (auto& item : algorithms_labels) {
        if(item.compare(str))
        {
            return true;
        }
    }
    return false;
    
}

bool CheckFitnessNames(std::string str)
{
    for (auto& item : fitness_labels) {
        if(item.compare(str))
        {
            return true;
        }
    }    
    return false;
    
}

bool Utils::ParseShell(int argc, char *argv[])
{
   
   int opt= 0;
   static const char *optString = "a:f:";
   bool err_flag = false;
    while ((opt = getopt(argc, argv,optString)) != -1) {
        switch (opt) {
             case 'a' : 
                    this->_shellParam.SetAlgorithmName(optarg);                 
                 break;
             case 'f' : ;
                    this->_shellParam.SetFitnessFunction(optarg);
                 break;
             default: this->PrintUsage(); 
                 exit(EXIT_FAILURE);
        }
    }

   if(!CheckParameterSyntax())
   {
       err_flag = true;
   }
   #ifdef DBG_PRINT
   std::cout << "err_flag = " <<(err_flag ? "true" : "false")<< std::endl;  
   #endif
   
   return err_flag;
}
Utils::Utils() {
}

Utils::~Utils() {
}


bool Utils::CheckParameterSyntax()
{


    if(  this->getEnum(algorithms_labels, this->_shellParam.GetAlgorithmName()) &&
         this->getEnum(fitness_labels, this->_shellParam.GetFitnessFunction())   )
    {
        return true;
    }
    
    return false;
}

