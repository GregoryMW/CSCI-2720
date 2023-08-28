Name of Program: main.cpp

This program takes in values from a given .txt file and uses generic constructors to initialize a binary search tree. The user then has access to a number of different functions
that can be used to print the tree, gives certain values, or modify the tree altogether.

The getNumSingleParent method is a function that returns the number nodes that have only one child node. This function works by recursively going through the entire tree,
increasing a counter by 1 each time it encounters a node with only one child node linked to it. This function has a complexity of O(n), as it is making a comparison
for every value in the tree.

The getNumLeafNodes method is a function that retusn the number of leaf nodes in the tree. This function works by recursively going through the tree, and incrementing
a count by 1 every time it encounters a node that has both the left and right nodes set to NULL. This function has a complexity of O(n), similar to the getNumSingleParent
in how it goes through the entire tree making comparisons to each value.

The getSumOfSubtrees method is a function that finds a node based off of a user-given criteria, and returns the sum of all the values of the subtree(s) of the given node.
This function first iterates through the tree until it finds the desired node (or potentially not at all), it then recursively travels through all of the nodes contained
within the subtree(s) of the user-defined node, adding all of their values and returning it back to the user. This function has a complexity of (N LogN), as it iterates
until it reaches the desired node, then recursively adds all the data values in the subtree(s).

CODER: Gregory Woolsey gmw30589@uga.edu

How to compile: g++ -g -Wall -o main main.cpp BinaryTree.cpp

OR use the included makefile
make

How to run:
main [input file]

The files int-input1.txt, float-input1.txt and string-input1.txt are given in the BinarySearchTree folder of the assignment.
