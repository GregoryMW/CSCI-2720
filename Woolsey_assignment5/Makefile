all: main main2

main2: main2.o Sorting.o
	g++ -g -Wall -o main2 main2.o Sorting.o

main: main.o Sorting.o
	g++ -g -Wall -o main main.o Sorting.o

main2.o: main2.cpp Sorting.h
	g++ -g -c -Wall main2.cpp

main.o: main.cpp Sorting.h
	g++ -g -c -Wall main.cpp

Sorting.o: Sorting.cpp Sorting.h
	g++ -g -c -Wall Sorting.cpp

clean:
	rm -f *.o main main2
