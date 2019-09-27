# MOAL - Metaheuristics Optimization Algorithms Library 
# 
MOAL is a collection of metaheuristics optimization algorithms bioispered.
It has been developed in C++, and has no external library dependencies.
For now, there is only a Genetic Algorithm implemented, but we are planning to include other algortihms.

# Compilation
To compile the library simply run:

$ make

You can customize the compilation (static, dynamic). You can print all dbg_print to follow the
algorithm running modifing the config.mk file:

$ config.mk

$ DBG_PRINT?=y

# Example
In the project there is a folder called test, there you can find an example on how to integrate MOAL in your
projects.



