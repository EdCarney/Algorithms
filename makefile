main.exe: heap-sort.o set.o graph.o mst-kruskal.o
	gcc -o ./main.exe ./src/main.c ./heap-sort.o ./set.o ./graph.o ./mst-kruskal.o
mst-kruskal.o: graph.o set.o
	gcc -c -g -o ./mst-kruskal.o ./src/graph-algos/mst-kruskal.c
graph.o: utilities.o
	gcc -c -g -o ./graph.o ./src/graph-algos/graph.c
utilities.o:
	gcc -c -g -o ./utilities.o ./src/utils/utilities.c
heap-sort.o:
	gcc -c -g -o ./heap-sort.o ./src/sorting-algos/heap-sort.c
set.o:
	gcc -c -g -o ./set.o ./src/graph-algos/set.c