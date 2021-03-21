main.exe: utilities.o treap-sort.o
	gcc -o ./bin/main.exe ./src/main.c ./bin/treap-sort.o ./bin/utilities.o -lm
treap-sort.o:
	gcc -c -g -o ./bin/treap-sort.o ./src/sorting-algos/treap-sort.c
utilities.o:
	gcc -c -g -o ./bin/utilities.o ./src/utils/utilities.c