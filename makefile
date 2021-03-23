main.exe: utilities.o treap-sort.o
	gcc -o ./main.exe ./src/main.c ./treap-sort.o ./utilities.o -lm
treap-sort.o:
	gcc -c -g -o ./treap-sort.o ./src/sorting-algos/treap-sort.c
utilities.o:
	gcc -c -g -o ./utilities.o ./src/utils/utilities.c