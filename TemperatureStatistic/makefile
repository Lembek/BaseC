all: statistic

statistic: main.o temp_functions.o
	gcc -o statistic main.o temp_functions.o

main.o: main.c temp_functions.h
	gcc -c -o main.o main.c

temp_functions.o: temp_functions.c
	gcc -c -o temp_functions.o temp_functions.c

clean:
	del *.o statistic.exe  