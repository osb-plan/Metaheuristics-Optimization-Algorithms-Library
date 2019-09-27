/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Utils.h
 * Author: utente
 *
 * Created on June 27, 2019, 8:26 PM
 */

#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <iostream>

#include "ShellParameters.h"
#include "fitness_functions_defs.h"
#include "algorithm_names_defs.h"

class Utils {

public:
    Utils();
    bool ParseShell(int argc, char *argv[]);
   
    ~Utils();
    
    void PrintUsage();

    ShellParameters GetShellParam() const {
        return _shellParam;
    }

    void SetShellParam(ShellParameters _shellParam) {
        this->_shellParam = _shellParam;
    }

    template<typename T>
    bool getEnum(T arr, std::string str)
    {
        for(unsigned int cnt = 0; cnt < arr.size(); cnt++)
        {
            if(!arr.at(cnt).compare(str))
                return true;
        }
        return false;    
    }    
    
    template<typename T>
    std::vector<T> GiveMeArray(unsigned int len, unsigned int normalized = 1)
    {
        std::vector<T> vect;
        for(unsigned int i = 0; i < len; i++)
        {
            float value = (float)rand()/normalized;
            std::cout << value << std::endl;
            vect.push_back(value);
        }
	return vect;
    }    
private:
    
    bool CheckParameterSyntax();
    ShellParameters _shellParam;
    

};

#endif /* UTILS_H */

