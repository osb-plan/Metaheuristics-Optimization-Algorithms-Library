/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Individuals.h
 * Author: utente
 *
 * Created on July 6, 2019, 12:38 AM
 */

#ifndef INDIVIDUALS_H
#define INDIVIDUALS_H
#include <vector>
#include "architecture.h"

template<class T>
class Individuals {
public:

    Individuals();

    //Individuals(const Individuals& orig);

    Individuals(std::vector<T> pos, double fit);
 
    

    std::vector<T> GetPositions() const {
        return _positions;
    }


    void SetPositions(std::vector<T> positions) {
        this->_positions = positions;
    }

    double GetFitness() const {
        return _fitness;
    }

    void SetFitness(double fitness) {
        this->_fitness = fitness;
    }

    void SetCrossProbability(double probability)
    {
        _cross_probability = probability;
    }
    
    double GetCrossProbability() const
    {
	return this->_cross_probability;
    }

    bool operator < (const Individuals<_ARCH>&  ind) const
    {
        #ifdef ROULETTE
            return (_cross_probability > ind._cross_probability);
        #else
            return (_fitness > ind._fitness);
        #endif

    }
private:
    std::vector<T> _positions;
    double _fitness = 0;
    double _cross_probability = 0;
};



#endif /* INDIVIDUALS_H */

