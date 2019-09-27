/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GeneticAlgorith.cpp
 * Author: utente
 * 
 * Created on July 5, 2019, 11:00 AM
 */

#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <random>

#include "../include/GeneticAlgorithm.h"
#include "../include/Individuals.h"
#include "../include/Utils.h"

GeneticAlgorithm::GeneticAlgorithm() {
    
}

GeneticAlgorithm::GeneticAlgorithm(
            bool all_parameters_set,
            unsigned int n_of_individuals,
            unsigned int n_iterations,
            unsigned int n_dimensions,
            FitnessFunctionMgmt fit_mgmt) :

    _all_parameters_set(all_parameters_set),
    _n_of_individuals(n_of_individuals),
    _n_iterations(n_iterations),
    _n_dimensions(n_dimensions),
    _fit_mgmt(fit_mgmt)
{

    
    
}

void GeneticAlgorithm::CalculateRoulette()
{
    double sum = 0;
    double minimum = RAND_MAX;

    for(Individuals<float> ind : population)
    {
        if(ind.GetFitness() < minimum)
        {
            minimum = ind.GetFitness();
        }
    }    

    double correction = 0;
    if(minimum < 0) 
    {
        correction = std::fabs(minimum);
    }else
    {
    }

    /* For probability I want all positive */ 
    for(Individuals<float> ind : population)
    {
        sum = sum + ind.GetFitness() + correction;
    }    
    #ifdef DBG_PRINT
    std::cout << "[DEBUG   ]: Minimum fitness =" << minimum << std::endl;
    std::cout << "[DEBUG   ]: sum of all fitness = " << sum << std::endl; 
    #endif
    for(Individuals<float>& ind : population)  
    {
        ind.SetCrossProbability(
             (ind.GetFitness() + correction)/sum
        );
    #ifdef DBG_PRINT
        std::cout <<"[DEBUG   ]: Individual("
                  << ind.GetPositions().at(0) << ","
                  << ind.GetPositions().at(1) << ")" << "\tRoulette = "
                  << ind.GetCrossProbability() 
                  << std::endl;
    #endif
    }   
}

std::vector<uint32_t> GeneticAlgorithm::GetIdx_Roulette(std::vector<float> vec)
{
    srand(time(0));
    std::vector<uint32_t> idx;
    float max_vec = *std::max_element(vec.begin(), vec.end());
    for(int cnt = 0; cnt < 2; cnt++)
    {
        double r = (static_cast<double>(rand())/RAND_MAX) * max_vec;
        #ifdef DBG_PRINT
        std::cout << "[DEBUG   ]: Roulette Val[" << cnt << "]"
                  << " = " << r << std::endl;
        #endif
        for(unsigned int y = 0; y < population.size() - 1; y++)
        {
            if(r > vec.at(y) &&  
               r < vec.at(y + 1))
            {
               
               #ifdef DBG_PRINT
               std::cout << "[DEBUG   ]: Find index = " << y << std::endl;
               #endif
               idx.push_back(y);
            }
        }
    }
    
    return idx;
}

bool GeneticAlgorithm::Init()
{
    InitPopulation();
    PrintPopulation();
    return true;
}

Individuals<_ARCH> GeneticAlgorithm::Mutation(Individuals<_ARCH> ind)
{

    std::vector<Individuals<_ARCH> >res;
    std::random_device rd; 
    std::vector<float> new_ind;
    std::mt19937 eng(rd()); // seed the generator
    int _sign;
    std::uniform_real_distribution<> distr(0.01,1.0); // define the range
       
    std::vector<_ARCH> pos = ind.GetPositions(); 
    _sign = (distr(eng) < 0.5) ? -1 : 1; 
    new_ind.push_back( pos.at(0) * (1 + (_sign*0.2)) );
    _sign = (distr(eng) < 0.5) ? -1 : 1; 
    new_ind.push_back(pos.at(1) * (1 + (_sign*0.2)) );

    Individuals<_ARCH> ret_ind;
    ret_ind.SetPositions(new_ind);
    _fit_mgmt.CalculateFitness(ret_ind);
   
    #ifdef DBG_PRINT
    std::cout << "Which individuals has been generated:" << new_ind.at(0)
             << " " << new_ind.at(1) << std::endl;
    #endif
             
    return ret_ind;

}

void GeneticAlgorithm::PrintPopulation()
{
    for(unsigned int i = 0; i < population.size(); i++)
    {
        Individuals<_ARCH> ind;
        ind = population.at(i);
        #ifdef DBG_PRINT
        std::cout << "[" << i << "] FIT = " << ind.GetFitness() 
                  << " (x,y) = " << ind.GetPositions().at(0) << "," <<
                                    ind.GetPositions().at(0) 
                  << std::endl;
        #endif
     }


}
GeneticAlgorithm::~GeneticAlgorithm() {
    // free here all things
}



std::vector<Individuals<_ARCH> > 
           GeneticAlgorithm::CrossOver(std::vector<Individuals<_ARCH> > vec)
{
    std::vector<Individuals<_ARCH> >res;
    std::random_device rd; 
    std::vector<float> new_ind;
    std::mt19937 eng(rd()); // seed the generator
    

    for(unsigned int dim = 0;  dim < _n_dimensions; dim++)
    {

        #ifdef DBG_PRINT
         std::cout << "[DEBUG   ]: IND1: " << 
                      vec.at(0).GetPositions().at(dim) << std::endl;
         std::cout << "[DEBUG   ]: IND2: " << 
                      vec.at(1).GetPositions().at(dim) << std::endl;
        #endif
    }

    for(unsigned int j = 0; j < 2; j++)
    {
        for(unsigned int dim = 0; dim < _n_dimensions; dim++)
        {

            std::uniform_real_distribution<> distr(0.9,1.0); // define the range
            new_ind.push_back( 
                            (((vec.at(0).GetPositions().at(dim) + 
                               vec.at(1).GetPositions().at(dim) ))/2) *
                               distr(eng)      
				 );
            
        }
        Individuals<_ARCH> ind;
        ind.SetPositions(new_ind);
        _fit_mgmt.CalculateFitness(ind);
        res.push_back(ind);
        new_ind.clear();
    }

    for(unsigned int dim = 0; dim < 2; dim++)
    {
        #ifdef DBG_PRINT
        std::cout << "DIM = " << dim << std::endl;

        std::cout << "[DEBUG   ]: IND1: " << 
                     res.at(0).GetPositions().at(dim) << std::endl;
        std::cout << "[DEBUG   ]: IND2: " << 
                     res.at(1).GetPositions().at(dim) << std::endl;
        #endif
    }
    return res;
}

void GeneticAlgorithm::Run(){
   
    for(unsigned int i = 0; i <_n_iterations; i++)
    {

        CalculateRoulette();
        SortPopulation(); 
        std::vector<float> vec_roulette = BuildProbability();
        std::vector<unsigned int> vec = GetIdx_Roulette(vec_roulette);   
        std::vector<Individuals<_ARCH> >  inds;
	inds.push_back(population.at(vec.at(0)));
	inds.push_back(population.at(vec.at(1)));
        std::vector<Individuals<_ARCH> > res = CrossOver(inds);
        population.at(vec.at(0)) = res.at(0);
        population.at(vec.at(1)) = res.at(1);
        
        std::vector<unsigned int> vec_mut = GetIdx_Roulette(vec_roulette);   
        Individuals<_ARCH> ind = Mutation(population.at(vec_mut.at(0)));

        population.at(vec_mut.at(0)) = ind;

	PrintPopulation();
        PrintBest(i); 
    }
}

void GeneticAlgorithm::PrintBest(unsigned int it)
{
  
    double minimum = RAND_MAX;

    for(Individuals<float> ind : population)
    {
        if(ind.GetFitness() < minimum)
        {
            minimum = ind.GetFitness();
        }
    }    

    std::cout << "[BEST] - [" << it << "] = " <<  minimum << std::endl;
}

std::vector<float> GeneticAlgorithm::BuildProbability()
{
    std::vector<float> prob;
    prob.push_back(0);
    double sum = 0;

    for(unsigned int i = population.size() - 1; i > 0 ; i--)
    {
        #ifdef DBG_PRINT
 	std::cout << "i " << 
                          population.at(i).GetCrossProbability() << std::endl;        
        std::cout << "i-1  " <<	
                             population.at(i - 1).GetCrossProbability() 
                             << std::endl;
        #endif 
        sum = (sum + population.at(i).GetCrossProbability()+
                     population.at(i - 1).GetCrossProbability());

        prob.push_back(sum);

    }

    #ifdef DBG_PRINT
     for(unsigned int i = 0; i < prob.size(); i++)
    {
        std::cout << "[DEBUG   ]: Probability " << prob.at(i) << std::endl;
    }
    #endif
    return prob;
}

void GeneticAlgorithm::InitPopulation()
{
    Utils UT;
    for(unsigned int cnt = 0; cnt < _n_of_individuals; cnt++)
    {
        Individuals<_ARCH> ind;
        ind.SetPositions(UT.template GiveMeArray<_ARCH>(_n_dimensions, RAND_MAX/10));
        
        /* Calculate Fitness */    
        _fit_mgmt.CalculateFitness(ind);
        
        population.push_back(ind);        
    }
    PrintPopulation();    
}

void GeneticAlgorithm::SortPopulation()
{
    std::sort(population.begin(), population.end());
}



