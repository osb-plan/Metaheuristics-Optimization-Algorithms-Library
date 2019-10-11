#ifndef PSO_FSO_H
#define PSO_FSO_H

#include "../include/FitnessFunctionMgmt.h"
#include "../include/Individuals.h"
#include "../include/Algorithm.h"
#include <vector>

class PsoFso : public Algorithm {

public:

    PsoFso();
    PsoFso(unsigned int n_individuals, unsigned int n_iterations) :
        _n_individuals(n_individuals),
        _n_iterations(n_iterations)
    {};

    virtual ~PsoFso();

    bool Init();
    bool InitPopulation();
    void UpdateVelocities();
    void UpdatePositions();
    
    void UpdateSingleVelocity();
    void UpdateSinglePosition(unsigned int ind_idx);
    
    void UpdatePersonalBest(unsigned int ind_idx);  
    void UpdateGlobalBest();

    void PrintPopulation(); 

    float& GetGlobalBest();
   

private:
    unsigned int _n_individuals;
    unsigned int _n_iterations;
    std::vector<_ARCH> _positions;
    std::vector<_ARCH> _velocites;
    std::vector<_ARCH> _global_best; // last value is fitness, first 
                                // n figures are positions of the global best
                                // individuals
    std::vector<_ARCH> _personal_best;

};



#endif 
