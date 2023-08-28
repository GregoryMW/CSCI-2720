main: main.o SortedLinkedList.o ItemType.o
	g++ -g -Wall -o main main.o ItemType.o SortedLinkedList.o

main.o: main.cpp ItemType.h ListNode.h SortedLinkedList.h
	g++ -g -c -Wall main.cpp

SortedLinkedList.o: SortedLinkedList.cpp SortedLinkedList.h ItemType.h ListNode.h
	g++ -g -c -Wall SortedLinkedList.cpp

ItemType.o: ItemType.cpp ItemType.h
	g++ -g -c -Wall ItemType.cpp

clean:
	rm -f *.o main
