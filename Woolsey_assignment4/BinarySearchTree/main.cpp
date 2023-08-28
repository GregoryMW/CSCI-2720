#include <cstddef>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <stdio.h>  
#include <cstdio>
#include "BinaryTree.h"

using namespace std;

int main(int argc, char *argv[])
{
  //Making sure only 1 input file is given
  if (argc != 2)
    {
      cout << "Please give one input text file." << endl;
      return EXIT_FAILURE;
    }

  //Initial creation of the possible trees
  BinaryTree<int> intTree;
  BinaryTree<float> floatTree;
  BinaryTree<string> stringTree;
  ifstream txtFile;
  string str;

  int inputRun = 1;
  char input;
  while (inputRun)
    {
      //Used to determine which tree to use throughout the program and initializes the tree
      cout << "Enter list type (i - int, f - float, s - std::string): ";
      cin >> input;
      switch (input)
	{
	case 'i':
	  txtFile.open(argv[1]);
	  while (getline(txtFile, str))
	    {
	      stringstream ss(str);
	      int temp;
	      while (ss >> temp)
		{
		  intTree.insert(temp);
		}
	    }
	  txtFile.close();
	  inputRun = 0;
	  break;
	case 'f':
	  txtFile.open(argv[1]);
	  while (getline(txtFile, str))
	    {
	      stringstream ss(str);
	      float temp;
	      while (ss >> temp)
		{
		  floatTree.insert(temp);
		}
	    }
	  txtFile.close();
	  inputRun = 0;
	  break;
	case 's':
	  txtFile.open(argv[1]);
	  while (getline(txtFile, str))
	    {
	      stringstream ss(str);
	      string temp;
	      while (ss >> temp)
		{
		  stringTree.insert(temp);
		}
	    }
	  txtFile.close();
	  inputRun = 0;
	  break;
	default:
	  cout << "\nPlease enter a valid input type." << endl;
	  break;
	}
    }

  int running = 1;
  bool found = false;
  while (running)
    {
      //Prompts the user to enter one of the possible choices to perform a given action
      cout << "\nCommands:\ninsert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order (p), post-order (o), getNumSingleParent (s), getNumLeafNodes (f), getSumOfTrees (t), quit(q)\nEnter a command: ";
      char command;
      cin >> command;
      switch (command)
	{
	  //insert method
	case 'i':
	  cout << "\nItem to insert: ";
	  switch (input)
	    {
	    case 'i':
	      int insertInt;
	      cin >> insertInt;
	      intTree.insert(insertInt);
	      intTree.inOrder();
	      break;
	    case 'f':
	      float insertFloat;
	      cin >> insertFloat;
	      floatTree.insert(insertFloat);
	      floatTree.inOrder();
	      break;
	    case 's':
	      string insertString;
	      cin >> insertString;
	      stringTree.insert(insertString);
	      stringTree.inOrder();
	      break;
	    }
	  break;
	  //deleteItem method
	case 'd':
	  cout << "\nItem to delete: ";
	  switch (input)
	    {
	    case 'i':
	      int deleteInt;
	      cin >> deleteInt;
	      intTree.deleteItem(deleteInt);
	      intTree.inOrder();
	      break;
	    case 'f':
	      float deleteFloat;
	      cin >> deleteFloat;
	      floatTree.deleteItem(deleteFloat);
	      floatTree.inOrder();
	      break;
	    case 's':
	      string deleteString;
	      cin >> deleteString;
	      stringTree.deleteItem(deleteString);
	      stringTree.inOrder();
	      break;
	    }
	  break;
	case 'r':
	  //retrieve method
	  found = false;
	  cout << "\nItem to be retrieved: ";
	  switch (input)
	    {
	    case 'i':
	      int findInt;
	      cin >> findInt;
	      intTree.retrieve(findInt, found);
	      break;
	    case 'f':
	      float findFloat;
	      cin >> findFloat;
	      floatTree.retrieve(findFloat, found);
	      break;
	    case 's':
	      string findString;
	      cin >> findString;
	      stringTree.retrieve(findString, found);
	      break;
	    }
	  if (found)
	    {
	      cout << "\nItem found in tree." << endl;
	    }
	  else
	    {
	      cout << "\nItem not in tree." << endl;
	    }
	  break;
	case 'l':
	  //getLength method
	  switch (input)
	    {
	    case 'i':
	      cout << "\nTree Length: " << intTree.getLength() << endl;
	      break;
	    case 'f':
	      cout << "\nTree Length: " << floatTree.getLength() << endl;
	      break;
	    case 's':
	      cout << "\nTree Length: " << stringTree.getLength() << endl;
	      break;
	    }
	  break;
	case 'n':
	  //inOrder method
	  switch (input)
	    {
	    case 'i':
	      intTree.inOrder();
	      break;
	    case 'f':
	      floatTree.inOrder();
	      break;
	    case 's':
	      stringTree.inOrder();
	      break;
	    }
	  break;
	case 'p':
	  //preOrder method
	  switch (input)
	    {
	    case 'i':
	      intTree.preOrder();
	      break;
	    case 'f':
	      floatTree.preOrder();
	      break;
	    case 's':
	      stringTree.preOrder();
	      break;
	    }
	  break;
	case 'o':
	  //postOrder method
	  switch (input)
	    {
	    case 'i':
	      intTree.postOrder();
	      break;
	    case 'f':
	      floatTree.postOrder();
	      break;
	    case 's':
	      stringTree.postOrder();
	      break;
	    }
	  break;
	case 's':
	  //getNumSingleParent method
	  switch (input)
	    {
	    case 'i':
	      cout << "\nNumber of Single Parents: " << intTree.getNumSingleParent() << endl;
	      break;
	    case 'f':
	      cout << "\nNumber of Single Parents: " << floatTree.getNumSingleParent() << endl;
	      break;
	    case 's':
	      cout << "\nNumber of Single Parents: " << stringTree.getNumSingleParent() << endl;
	      break;
	    }
	  break;
	case 'f':
	  //getNumLeafNodes method
	  switch (input)
	    {
	    case 'i':
	      cout << "\nNumber of leaf nodes: " << intTree.getNumLeafNodes() << endl;
	      break;
	    case 'f':
	      cout << "\nNumber of lead nodes: " << floatTree.getNumLeafNodes() << endl;
	      break;
	    case 's':
	      cout << "\nNumber of leaf nodes: " << stringTree.getNumLeafNodes() << endl;
	      break;
	    }
	  break;
	case 't':
	  //getSumOfSubTrees method
	  cout << "\nItem to get sum of subtrees: ";
	  switch (input)
	    {
	    case 'i':
	      int intSum;
	      cin >> intSum;
	      intTree.getSumOfSubtrees(intSum);
	      break;
	    case 'f':
	      float floatSum;
	      cin >> floatSum;
	      floatTree.getSumOfSubtrees(floatSum);
	      break;
	    case 's':
	      string stringSum;
	      cin >> stringSum;
	      stringTree.getSumOfSubtrees(stringSum);
	      break;
	    }
	  break;
	case 'q':
	  //Quit program
	  cout << "\nQuitting Program..." << endl;
	  running = 0;
	  break;
	default:
	  cout << "\nCommand not recognized. Try again." << endl;
	  break;
	}
    }
  return EXIT_SUCCESS;
}

