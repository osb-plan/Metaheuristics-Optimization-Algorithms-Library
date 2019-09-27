/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GeneticAlgorith.h
 * Author: utente
 *
 * Created on July 5, 2019, 11:00 AM
 */

#ifndef GENETICALGORITH_H
#define GENETICALGORITH_H
#include <vector>

#include "../include/FitnessFunctionMgmt.h"
#include "../include/Individuals.h"
#include "../include/Algorithm.h"

class GeneticAlgorithm : public Algorithm {
    

public:
    GeneticAlgorithm();
    GeneticAlgorithm(
                bool _all_parameters_set,
                unsigned int _n_of_individuals,
                unsigned int _n_iterations,
                unsigned int _n_dimensions,
                FitnessFunctionMgmt _fit_mgmt
    );
    
    virtual ~GeneticAlgorithm();

    bool Init();
    void InitPopulation();
    void AllocateRoulette();
    std::vector<float> BuildProbability();
    void CalculateRoulette();
    std::vector<uint32_t> GetIdx_Roulette(std::vector<float> vec);
    void PrintPopulation();
    void Run();
    void SortPopulation();
    void RunOneIteration();
    std::vector<Individuals<_ARCH> > 
               CrossOver(std::vector<Individuals<_ARCH> > vec);
    Individuals<_ARCH> Mutation(Individuals<_ARCH> ind);
    
    bool IsAll_parameters_set() const {
        return _all_parameters_set;
    }

    void SetAll_parameters_set(bool _all_parameters_set) {
        this->_all_parameters_set = _all_parameters_set;
    }

    FitnessFunctionMgmt GetFit_mgmt() const {
        return _fit_mgmt;
    }

    void SetFit_mgmt(FitnessFunctionMgmt _fit_mgmt) {
        this->_fit_mgmt = _fit_mgmt;
    }

    unsigned int GetN_bits() const {
        return _n_bits;
    }

    void SetN_bits(unsigned int _n_bits) {
        this->_n_bits = _n_bits;
    }

    unsigned int GetN_iterations() const {
        return _n_iterations;
    }

    void SetN_iterations(unsigned int _n_iterations) {
        this->_n_iterations = _n_iterations;
    }

    unsigned int GetN_of_individuals() const {
        return _n_of_individuals;
    }

    void SetN_of_individuals(unsigned int _n_of_individuals) {
        this->_n_of_individuals = _n_of_individuals;
    }
    void PrintBest(unsigned int it);
private:
    bool _all_parameters_set;
    unsigned int _n_bits;
    unsigned int _n_of_individuals;
    unsigned int _n_iterations;
    unsigned int _n_dimensions;
    FitnessFunctionMgmt _fit_mgmt;
    float **_roulette;

    std::vector<Individuals<_ARCH> > population;
};

#endif /* GENETICALGORITH_H */

