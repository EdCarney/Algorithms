main.exe: selection-sort.o insertion-sort.o utilities.o
	gcc -o .\bin\main.exe .\src\main.c .\bin\selection-sort.o .\bin\insertion-sort.o .\bin\utilities.o
selection-sort.o:
	gcc -c -g -o .\bin\selection-sort.o .\src\selection-sort.c
insertion-sort.o:
	gcc -c -g -o .\bin\insertion-sort.o .\src\insertion-sort.c
utilities.o:
	gcc -c -g -o .\bin\utilities.o .\src\utilities.c