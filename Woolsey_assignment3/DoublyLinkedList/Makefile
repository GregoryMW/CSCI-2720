main: main.o DoublyLinkedList.o
	g++ -g -Wall -o main main.o DoublyLinkedList.o

main.o: main.cpp DoublyLinkedList.h
	g++ -g -c -Wall main.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	g++ -g -c -Wall DoublyLinkedList.cpp

clean:
	rm -f *.o main
