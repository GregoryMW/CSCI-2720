#include <cstddef>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <stdio.h>  
#include <cstdio>
#include "ItemType.h"
#include "ListNode.h"
#include "SortedLinkedList.h"

using namespace std;

int main(int argc, char *argv[])
{
  //Making sure only 1 inpupt file is given
  if (argc != 2)
    {
      cout << "Please give one input text file." << endl;
      return EXIT_FAILURE;
    }

  //Creation of the inital list. Takes in the numbers given from the file
  SortedLinkedList list;
  ifstream txtFile;
  string str;
  txtFile.open(argv[1]);
  while (getline(txtFile, str))
    {
      stringstream ss(str);
      int temp;
      while (ss >> temp)
	{
	  ItemType item;
	  item.initialize(temp);
	  list.insertItem(item);
	}
    }
  txtFile.close();
  list.resetList();

  cout << "\nCommands:\n(i) - Insert Value\n(d) - Delete value\n(s) - Search Value\n(n) - Print next iterator value\n(r) - Reset iterator";
  cout << "\n(a) - Delete alternate nodes\n(m) - merge two lists\n(t) - Intersection";
  cout << "\n(p) - Print list\n(l) - Print length\n(q) - Quit Program" << endl;

  char input;
  int running = 1;
  while (running)
    {
      cout << "\nEnter a command: ";
      cin >> input;

      switch(input){
      case 'i':
	{
	  //Takes in a number, creates an ItemTyppe object from it, and adds that object in
	  //the approppriate spot in the list
	  int iNum;
	  list.printList();
	  cout << "\nEnter number: ";
	  cin >> iNum;
	  ItemType iItem;
	  iItem.initialize(iNum);
	  list.insertItem(iItem);
	  list.printList();
	  break;
	}
      case 'd':
	{
	  //Takes in a number, creates an ItemType object, and uses it to find a matching node to delete
	  int dNum;
	  list.printList();
	  cout << "\nEnter value to delete: ";
	  cin >> dNum;
	  ItemType dItem;
	  dItem.initialize(dNum);
	  list.deleteItem(dItem);
	  list.printList();
	  break;
	}
      case 's':
	{
	  //Traverses through the list to find the given value, then returns its index
	  int sNum;
	  cout << "\nEnter value to search: ";
	  cin >> sNum;
	  ItemType sItem;
	  sItem.initialize(sNum);
	  cout << "\nIndex " << list.searchItem(sItem) << endl;
	  break;
	}
      case 'n':
	{
	  //This allows the user to iterate through the data members of the list
	  ItemType nextItem;
	  nextItem.initialize(list.getNextItem().getValue());
	  if (nextItem.getValue() != -1 && nextItem.getValue() != -2)
	    cout << nextItem.getValue() << endl;
	  if (nextItem.getValue() == -1)
	    cout << "List is Empty." << endl;
	  if (nextItem.getValue() == -2)
	    cout << "The end of the list has reached." << endl;
	  break;
	}
      case 'r':
	{
	  //This will reset the iterator to the head of the list
	  cout << "Iterator reset." << endl;
	  list.resetList();
	  break;
	}
      case 'a':
	{
	  //This will delete every other data member of the list, starting with that
	  //at index 1
	  cout << "\nList before alternate delete: ";
	  list.printList();
	  list.resetList();
	  int count = 1;
	  ItemType tbd;
	  while (count <= list.length() / 2 + 1)
	    {
	      list.resetList();
	      for (int i = 0; i < list.length(); i ++)
		{
		  tbd.initialize(list.getNextItem().getValue());
		  if(list.searchItem(tbd) == count)
		    {
		      list.deleteItem(tbd);
		      break;
		    }
		}
	      count ++;
	    }
	  cout << "\nList after alternate delete: ";
	  list.printList();
	  list.resetList();
	  break;
	}
      case 'm':
	{
	  //This will take in user-defined numbers, create a list out of them, and then checks to see if
	  //there are any matching data members between the two lists. If there are, the operation is cancelled;
	  //if there aren't the two lists are merged together
	  int mergeLen;
	  string mergeNums;
	  cout << "\nLength of list to merge: ";
	  cin >> mergeLen;
	  cout << "\nList elements separated by spaces in order: ";
	  cin.ignore();
	  getline(cin, mergeNums);
	  SortedLinkedList mergeList;
	  stringstream ns(mergeNums);
	  int temp;
	  while (ns >> temp)
	    {
	      ItemType item;
	      item.initialize(temp);
	      mergeList.insertItem(item);
	    }
	  cout << "\nList 1: ";
	  list.printList();
	  cout << "\nList 2: ";
	  mergeList.printList();
	  list.resetList();
	  mergeList.resetList();
	  ItemType listVal;
	  ItemType mergeVal;
	  int duplicate = 0;
	  for (int i = 0; i < mergeList.length(); i ++)
	    {
	      mergeVal = mergeList.getNextItem();
	      for (int j = 0; j < list.length(); j ++)
		{
		  listVal = list.getNextItem();
		  if (mergeVal.getValue() == listVal.getValue())
		    {
		      duplicate = 1;
		      break;
		    }
		}
	      if (duplicate)
		break;
	    }
	  if (duplicate)
	    {
	      cout << "\nSorry. You cannot insert the duplicate item." << endl;
	      list.printList();
	      break;
	    }
	  else
	    {
	      mergeList.resetList();
	      for (int i = 0; i < mergeList.length(); i ++)
		{
		  list.insertItem(mergeList.getNextItem());
		}
	    }
	  list.resetList();
	  cout << endl;
	  list.printList();
	  break;
	}
      case 't':
	{
	  //Very similar to the merge operation above, this will compare two lists. But oppposite of the merge
	  //operation, this will find and list any and all the matching data members between the two lists.
	  int intLen;
	  string intNums;
	  cout << "\nLength of list to find intersection ";
	  cin >> intLen;
	  cout << "\nList elements separated by spaces in order: ";
	  cin.ignore();
	  getline(cin, intNums);
	  SortedLinkedList intList;
	  stringstream ts(intNums);
	  int temp;
	  while (ts >> temp)
	    {
	      ItemType item;
	      item.initialize(temp);
	      intList.insertItem(item);
	    }
	  cout << "\nList 1: ";
	  list.printList();
	  cout << "\nList 2: ";
	  intList.printList();
	  list.resetList();
	  intList.resetList();
	  SortedLinkedList intersection;
	  ItemType listVal;
	  ItemType intVal;
	  for (int i = 0; i < intList.length(); i ++)
	    {
	      intVal = intList.getNextItem();
	      list.resetList();
	      for (int j = 0; j < list.length(); j ++)
		{
		  listVal = list.getNextItem();
		  if (intVal.getValue() == listVal.getValue())
		    {
		      intersection.insertItem(intVal);
		      break;
		    }
		}
	    }
	  cout << "\nIntersection: ";
	  intersection.printList();
	  list.resetList();
	  break;
	}
      case 'p':
	{
	  //Prints the data members in the list
	  cout << endl;
	  list.printList();
	  break;
	}
      case 'l':
	{
	  //Simply gives the length of the current list
	  cout << "List length is " << list.length() << endl;
	  break;
	}
      case 'q':
	{
	  //Set running to 0, ending the program
	  running = 0;
	  break;
	}
      default:
	{
	  //User must give a valid command
	  cout << "\nInvalid command, try again!" << endl;
	}
      }
    }
  return EXIT_SUCCESS;
}
