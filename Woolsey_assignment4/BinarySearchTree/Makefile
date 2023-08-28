main: main.o BinaryTree.o
	g++ -g -Wall -o main main.o BinaryTree.o

main.o: main.cpp BinaryTree.h
	g++ -g -c -Wall main.cpp

BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -g -c -Wall BinaryTree.cpp

clean:
	rm -f *.o main
