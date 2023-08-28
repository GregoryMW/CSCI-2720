Name of Program: main.cpp

This program takes in values froma  given .txt file and uses generic constructors to initialize a list of the appropriate type. The user is then given
a number of options to choose from to perform certain operations to the list.

The deleteSubsection function involves iterating through the linked list (if needed) until reaching a value that is greater than the lower bound, and
smaller than the upper bound. Then an operation similar to that of deleteItem() is used to delete all values from there on that are also larger than
the lower bound and smaller than the upper bound. This function has a complexity of O(n), as it iterates to begin deletion, then continues the same iteration
as it deletes the necessary values.

The mode function involves choosing a value starting from the beginning of the list, and then iterating through the list to see how many times
the given values appears. This will continue until every value in the list has been accounted for, and then returns which value appeared the most
within the list, returning the first encountered vlaue is there are multiple values with the same number of appearances in the list. This function
has a complexity of O(n^2), as it will iterate for each value, and iterate within each iteration to count how many times the value appears.

The swapAlternate function involves taking every two values, and swapping their positions with each other without simply swapping their two data members.
This involves appropriately tracking every next and back node involved and properly setting them in order to pproperly perform the function. This function
has a complexity of O(n) due to its ierating through the list as it swaps every two values with each other.

CODER: Gregory Woolsey gmw30589@uga.edu

How to compile: g++ -g -Wall -o main main.cpp DoublyLinkedList.cpp

OR use the included makefile
make

How to run:
main [input file]

The files int-input.txt, int-input2.txt, float-input.txt and string-input.txt are given in the DoublyLinkedList folder of the assignment.
