# Overview
This repo branch contains code required for ENPM809X Project 1 (2021 Spring Semester).

# Source Control
This code is available on GitHub at https://github.com/EdCarney/Algorithms.git on the **ENPM809X-Project2** branch.

To clone the repository, ensure git is installed locally on your machine and execute the following in your command line:
```
git clone https://github.com/EdCarney/Algorithms.git
cd Algorithms
git checkout ENPM809X-Project2
```

# Repository Layout
```
.
|-- data                    # data to be ingested
|   |-- graph_info.txt      # graph information file to ingest and search against
|-- src                     # source code
|   |-- sorting-algos       # source code for heap
|   |-- graph-algos         # source code for all graph-related functions (sets, MST, Shortest Path, etc.)
|   |-- main.c              # main entrypoint
|-- makefile                # makefile for project
```

# Compilation and Execution
This project is intended to be compiled using make and gcc on a *nix platform (i.e. Linux or MacOS distribution) or on a
Windows platform with MinGW installed (and appropriate configuration to allow calling make and gcc from the CLI).

There is a **makefile** that can be used to compile the code. This outputs several *.o files for the various graph source files,
the heap source file, and a **main.exe** file. The **main.exe** file can be run directly to output the project results.

In the project root directory, execute:
```
make
./main.exe
```

This should generate an output similar to the following:
```
Adjacency List Values (NODE ID, WEIGHT)
-----------------------------------------
VERTEX 1:       (2, 15) (5, 8) (16, 14) (19, 4) (20, 15)
VERTEX 2:       (1, 15) (3, 17) (5, 9) (14, 19) (16, 14) (20, 16)
VERTEX 3:       (2, 17) (4, 20) (7, 14) (17, 1)
VERTEX 4:       (3, 20) (7, 12) (9, 13) (12, 1) (17, 2)
VERTEX 5:       (1, 8) (2, 9) (13, 14) (16, 7) (19, 20) (20, 1)
VERTEX 6:       (9, 9) (15, 8) (16, 16) (18, 16) (20, 4)
VERTEX 7:       (3, 14) (4, 12) (12, 13) (17, 15) (18, 16)
VERTEX 8:       (9, 6) (15, 14) (17, 14) (18, 4)
VERTEX 9:       (4, 13) (6, 9) (8, 6) (15, 20) (16, 7) (18, 12) (20, 5)
VERTEX 10:      (11, 16) (13, 6) (14, 11) (19, 14)
VERTEX 11:      (10, 16) (13, 20) (14, 11) (19, 3)
VERTEX 12:      (4, 1) (7, 13) (15, 17) (17, 6)
VERTEX 13:      (5, 14) (10, 6) (11, 20) (14, 7)
VERTEX 14:      (2, 19) (10, 11) (11, 11) (13, 7) (19, 8)
VERTEX 15:      (6, 8) (8, 14) (9, 20) (12, 17) (18, 6)
VERTEX 16:      (1, 14) (2, 14) (5, 7) (6, 16) (9, 7) (20, 2)
VERTEX 17:      (3, 1) (4, 2) (7, 15) (8, 14) (12, 6) 
VERTEX 18:      (6, 16) (7, 16) (8, 4) (9, 12) (15, 6)
VERTEX 19:      (1, 4) (5, 20) (10, 14) (11, 3) (14, 8)
VERTEX 20:      (1, 15) (2, 16) (5, 1) (6, 4) (9, 5) (16, 2)
-----------------------------------------

Kruskal MST Rooted at Node 1
-----------------------------------------
VERTEX: 3,      PARENT: 17,     WEIGHT: 1
VERTEX: 12,     PARENT: 4,      WEIGHT: 1
VERTEX: 20,     PARENT: 5,      WEIGHT: 1
VERTEX: 17,     PARENT: 4,      WEIGHT: 2
VERTEX: 16,     PARENT: 20,     WEIGHT: 2
VERTEX: 11,     PARENT: 19,     WEIGHT: 3
VERTEX: 6,      PARENT: 20,     WEIGHT: 4
VERTEX: 19,     PARENT: 1,      WEIGHT: 4
VERTEX: 18,     PARENT: 8,      WEIGHT: 4
VERTEX: 9,      PARENT: 20,     WEIGHT: 5
VERTEX: 10,     PARENT: 13,     WEIGHT: 6
VERTEX: 15,     PARENT: 18,     WEIGHT: 6
VERTEX: 8,      PARENT: 9,      WEIGHT: 6
VERTEX: 13,     PARENT: 14,     WEIGHT: 7
VERTEX: 14,     PARENT: 19,     WEIGHT: 8
VERTEX: 5,      PARENT: 1,      WEIGHT: 8
VERTEX: 2,      PARENT: 5,      WEIGHT: 9
VERTEX: 7,      PARENT: 4,      WEIGHT: 12
VERTEX: 4,      PARENT: 9,      WEIGHT: 13
VERTEX: 1,      PARENT: NULL,   WEIGHT: 0
TOTAL COST: 102
-----------------------------------------


Dijkstra Shortest Path From 3 To 19
-----------------------------------------
PATH: 19 > 1 > 5 > 20 > 9 > 4 > 17 > 3 > NULL
TOTAL COST: 34
-----------------------------------------
```
