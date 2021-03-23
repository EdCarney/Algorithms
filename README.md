# Overview
This repo branch contains code required for ENPM809X Project 1 (2021 Spring Semester).

# Repository Layout
```
.
|-- data                    # data to be ingested
|   |-- textbook.txt        # textbook file to ingest and search against
|   |-- treap-input.txt     # contains the array to define the treap
|-- src                     # source code
|   |-- sorting-algos       # source code for treap
|   |-- utils               # source code for utility methods (e.g. reading arrays from files)
|   |-- main.c              # main entrypoint
|-- makefile                # makefile for project
```

# Compilation and Execution
This project is intended to be compiled on a *nix platform (i.e. Linux or MacOS distribution).
There is a **makefile** that can be used to compile the code. This outputs *.o files for the treap and 
utility code and a **main.exe** file. The **main.exe** file can be run directly to output the project results.

In the project root directory, execute:
```
make
./main.exe
```

This should generate an output similar to the following:
```
PROBLEM 4: Random Priorities
Search Running Time (us): 4610.000000
Search Running Time (us): 4507.000000
Search Running Time (us): 4523.000000
Search Running Time (us): 4167.000000
Search Running Time (us): 4545.000000
Average Search Running Time (us): 4470.400000

PROBLEM 5: Character-Based Priorities
Search Running Time (us): 2916.000000
Search Running Time (us): 3381.000000
Search Running Time (us): 3193.000000
Search Running Time (us): 3376.000000
Search Running Time (us): 3654.000000
Average Search Running Time (us): 3304.000000

PROBLEM 6: No Priorities
Search Running Time (us): 8042.000000
Search Running Time (us): 8181.000000
Search Running Time (us): 7928.000000
Search Running Time (us): 7612.000000
Search Running Time (us): 7582.000000
Average Search Running Time (us): 7869.000000
```
