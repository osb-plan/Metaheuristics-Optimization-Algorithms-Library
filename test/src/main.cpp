// System Library
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// OAL 
#include "../../include/FitnessFunctionMgmt.h"
#include "../../include/Utils.h"
#include "../../include/Individuals.h"
#include "../../include/AlgorithmChecker.h"
#include "../../include/Algorithm.h"

int main(int argc, char *argv[])    
{
    Utils *UT = new Utils();
    
    if(UT->ParseShell(argc, argv))
    {
        UT->PrintUsage();
        UT->~Utils();
        delete(UT);
        return EXIT_FAILURE;
    }

    ShellParameters sPar = UT->GetShellParam();
    
    AlgorithmChecker AlgCk;
    AlgCk.MainRun(sPar.GetAlgorithmName(), sPar.GetFitnessFunction());
    
    return EXIT_SUCCESS;
}
