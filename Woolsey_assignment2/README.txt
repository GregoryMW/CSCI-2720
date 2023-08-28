Name of Program: main.cpp

This program takes in numbers from an input.txt file, creates a sorted linked list out of them, and allows the user to
perform a number of actions to modify the list.

For the merge function, user-specified numbers are taken in and a list is formed from them. The ppprogram then goes through
an operation with a complexity of O(n^2) in order to see if there are are matching numbers between the two lists.
If there are, the command prematurely ends; if not, the two lists will merge together, ending with an edited list
that contains all the numbers of both lists.

For the deleting alternate nodes function, the program loops through the list, deleting every other number starting
with that of index 1. This opperation has a complexity of O(n) and works by keeping a count of the desired index to
delete, and rescans the list uppon every deletion to compensate for changing indeces.

For the intersecting lists function, similar to the merge function, a user-specified list is taken in and every
number is compared to that of the original list. If there are any numbers that match, they are placed (sorted of course)
in a new list that is presented upon completion of the operation. This oppperation also works with a complexity
of O(n^2).

CODER: Gregory Woolsey gmw30589@uga.edu

How to compile: g++ -g -Wall -o main main.cpp SortedLinkedList.cpp ItemType.cpp

OR use the included makefile
make

How to run:
main [input file]

The files input.txt and empty.txt are given in the main folder of the assignment.
