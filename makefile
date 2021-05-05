main.exe: heap-sort.o set.o graph.o mst-kruskal.o shortest-path-dijkstra.o
	gcc -o ./main.exe ./src/main.c ./heap-sort.o ./set.o ./graph.o ./mst-kruskal.o ./queue.o ./shortest-path-dijkstra.o -lm
mst-kruskal.o: graph.o set.o heap-sort.o queue.o
	gcc -c -g -o ./mst-kruskal.o ./src/graph-algos/mst-kruskal.c
queue.o: graph.o
	gcc -c -g -o ./queue.o ./src/graph-algos/queue.c
shortest-path-dijkstra.o: graph.o set.o heap-sort.o
	gcc -c -g -o ./shortest-path-dijkstra.o ./src/graph-algos/shortest-path-dijkstra.c
graph.o:
	gcc -c -g -o ./graph.o ./src/graph-algos/graph.c
heap-sort.o:
	gcc -c -g -o ./heap-sort.o ./src/sorting-algos/heap-sort.c
set.o:
	gcc -c -g -o ./set.o ./src/graph-algos/set.c
