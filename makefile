main.exe: utilites.o
	gcc -o ./main.exe ./src/main.c ./utilities.o
utilites.o:
	gcc -c -g -o ./utilities.o ./src/utils/utilities.c