#include <cstddef>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <stdio.h>  
#include <cstdio>
#include "DoublyLinkedList.h"

using namespace std;

int main(int argc, char *argv[])
{
  //Making sure only 1 input file is given
  if (argc != 2)
    {
      cout << "Please give one input text file." << endl;
      return EXIT_FAILURE;
    }

  //Initial creation of the possible lists
  DoublyLinkedList<int> intList;
  DoublyLinkedList<float> floatList;
  DoublyLinkedList<string> stringList;
  ifstream txtFile;
  string str;

  int inputRun = 1;
  char input;
  while (inputRun)
    {
      //Used to determine which list to use throughout the program
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
		  intList.insertItem(temp);
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
		  floatList.insertItem(temp);
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
		  stringList.insertItem(temp);
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
  while (running)
    {
      //Prompts the user to enter one of the possible choices to perform a given action
      cout << "\ninsert (i), delete (d), length(l), print(p), deleteSub(b), mode(m), printReverse(r), swapAlt(s), quit(q)\nEnter a command: ";
      char command;
      cin >> command;
      switch (command)
	{
	case 'i':
	  cout << "\nItem to insert: ";
	  switch (input)
	    {
	    case 'i':
	      int insertInt;
	      cin >> insertInt;
	      intList.insertItem(insertInt);
	      intList.print();
	      break;
	    case 'f':
	      float insertFloat;
	      cin >> insertFloat;
	      floatList.insertItem(insertFloat);
	      floatList.print();
	      break;
	    case 's':
	      string insertString;
	      cin >> insertString;
	      stringList.insertItem(insertString);
	      stringList.print();
	      break;
	    }
	  break;
	case 'd':
	  cout << "\nItem to delete: ";
	  switch (input)
	    {
	    case 'i':
	      int deleteInt;
	      cin >> deleteInt;
	      intList.deleteItem(deleteInt);
	      intList.print();
	      break;
	    case 'f':
	      float deleteFloat;
	      cin >> deleteFloat;
	      floatList.deleteItem(deleteFloat);
	      floatList.print();
	      break;
	    case 's':
	      string deleteString;
	      cin >> deleteString;
	      stringList.deleteItem(deleteString);
	      stringList.print();
	      break;
	    }
	  break;
	case 'l':
	  switch (input)
	    {
	    case 'i':
	      cout << "\nThe length is: " << intList.lengthIs() << endl;
	      break;
	    case 'f':
	      cout << "\nThe length is: " << floatList.lengthIs() << endl;
	      break;
	    case 's':
	      cout << "\nThe length is: " << stringList.lengthIs() << endl;
	      break;
	    }
	  break;
	case 'p':
	  switch (input)
	    {
	    case 'i':
	      intList.print();
	      break;
	    case 'f':
	      floatList.print();
	      break;
	    case 's':
	      stringList.print();
	      break;
	    }
	  break;
	case 'b':
	  switch (input)
	    {
	    case 'i':
	      int lowerInt;
	      int upperInt;
	      cout << "\nEnter lower bound: ";
	      cin >> lowerInt;
	      cout << "\nEnter upper bound: ";
	      cin >> upperInt;
	      cout << "\nOriginal List: ";
	      intList.print();
	      intList.deleteSubsection(lowerInt, upperInt);
	      cout << "\nModified List: ";
	      intList.print();
	      break;
	    case 'f':
	      float lowerFloat;
	      float upperFloat;
	      cout << "\nEnter lower bound: ";
	      cin >> lowerFloat;
	      cout << "\nEnter upper bound: ";
	      cin >> upperFloat;
	      cout << "\nOriginal List: ";
	      floatList.print();
	      floatList.deleteSubsection(lowerFloat, upperFloat);
	      cout << "\nModified List: ";
	      floatList.print();
	      break;
	    case 's':
	      string lowerString;
	      string upperString;
	      cout << "\nEnter lower bound: ";
	      cin >> lowerString;
	      cout << "\nEnter upper bound: ";
	      cin >> upperString;
	      cout << "\nOriginal List: ";
	      stringList.print();
	      stringList.deleteSubsection(lowerString, upperString);
	      cout << "\nModified List: ";
	      stringList.print();
	      break;
	    }
	  break;
	case 'm':
	  switch (input)
	    {
	    case 'i':
	      intList.print();
	      cout << "\nMode: " << intList.mode();
	      break;
	    case 'f':
	      floatList.print();
	      cout << "\nMode: " << floatList.mode();
	      break;
	    case 's':
	      stringList.print();
	      cout << "\nMode: " << stringList.mode();
	      break;
	    }
	  break;
	case 'r':
	  switch (input)
	    {
	    case 'i':
	      intList.printReverse();
	      break;
	    case 'f':
	      floatList.printReverse();
	      break;
	    case 's':
	      stringList.printReverse();
	      break;
	    }
	  break;
	case 's':
	  switch (input)
	    {
	    case 'i':
	      cout << "\nOriginal List: ";
	      intList.print();
	      intList.swapAlternate();
	      cout << "\nSwapped List: ";
	      intList.print();
	      break;
	    case 'f':
	      cout << "\nOriginal List: ";
	      floatList.print();
	      floatList.swapAlternate();
	      cout << "\nSwapped List: ";
	      floatList.print();
	      break;
	    case 's':
	      cout << "\nOriginal List: ";
	      stringList.print();
	      stringList.swapAlternate();
	      cout << "\nSwapped List: ";
	      stringList.print();
	      break;
	    }
	  break;
	case 'q':
	  cout << "\nQuitting Program..." << endl;
	  running = 0;
	  break;
	}
    }
  return EXIT_SUCCESS;
}
