main.exe: selection-sort.o insertion-sort.o utilities.o binary-search-tree.o heap-sort.o treap-sort.o
	gcc -o ./bin/main.exe ./src/main.c ./bin/treap-sort.o ./bin/heap-sort.o ./bin/binary-search-tree.o ./bin/selection-sort.o ./bin/insertion-sort.o ./bin/utilities.o -lm
selection-sort.o:
	gcc -c -g -o ./bin/selection-sort.o ./src/sorting-algos/selection-sort.c
insertion-sort.o:
	gcc -c -g -o ./bin/insertion-sort.o ./src/sorting-algos/insertion-sort.c
binary-search-tree.o:
	gcc -c -g -o ./bin/binary-search-tree.o ./src/data-structures/binary-search-tree.c
heap-sort.o:
	gcc -c -g -o ./bin/heap-sort.o ./src/sorting-algos/heap-sort.c
treap-sort.o:
	gcc -c -g -o ./bin/treap-sort.o ./src/sorting-algos/treap-sort.c
utilities.o:
	gcc -c -g -o ./bin/utilities.o ./src/utils/utilities.c