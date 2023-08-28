#include <cstddef>
#include <iostream>
#include "ItemType.h"
#include "ListNode.h"
#include "SortedLinkedList.h"

//Constructor
SortedLinkedList::SortedLinkedList()
{
  head = NULL;
}

//Destructor
SortedLinkedList::~SortedLinkedList()
{
  ListNode *temp = head;
  while (temp != NULL)
    {
      ListNode *temp2 = temp->next;
      delete temp;
      temp = temp2;
    }
}


//Counts the number of data members to use as the length of the list
int SortedLinkedList::length() const
{
  int count = 0;
  ListNode *temp = head;
  while (temp != NULL)
    {
      count ++;
      temp = temp->next;
    }
  return count;
}

//Will take an ItemType object and locate the apppropriate location to place a new node
//containing that data member in order to make sure the list remains sorted
void SortedLinkedList::insertItem(ItemType item)
{
  ListNode *temp = new ListNode;
  temp->item.initialize(item.getValue());
  temp->next = NULL;

  if (head == NULL)
    {
      head = temp;
    }
  else
    {
      ListNode *ptr = head;
      ListNode *prev;
      while (ptr != NULL)
	{
	  switch(temp->item.compareTo(ptr->item))
	    {
	    case LESS:
	      {
		if (ptr == head)
		  {
		    temp->next = ptr;
		    head = temp;
		    return;
		  }
		else
		  {
		    prev->next = temp;
		    temp->next = ptr;
		    return;
		  }
		break;
	      }
	    case GREATER:
	      {
		if (ptr->next == NULL)
		  {
		    ptr->next = temp;
		    ptr = temp->next;
		  }
		else
		  {
		    prev = ptr;
		    ptr = ptr->next;
		  }
		break;
	      }
	    default:
	      std::cout << "Sorry, You cannot insert the duplicate item." << std::endl;
	    }
	}
    }
}

//This will go through the list in attempt to find the desired node to delete
void SortedLinkedList::deleteItem(ItemType item)
{
  ListNode *ptr = head;
  if (head == NULL)
    {
      std::cout << "You cannot delete from an empty list." << std::endl;
      return;
    }
  else if (head->next == NULL)
    {
      if (ptr->item.compareTo(item) == EQUAL)
	{
	  head = NULL;
	  return;
	}
    }
  else
    {
      if (head->item.compareTo(item) == EQUAL)
	{
	  head = head->next;
	  return;
	}
      ptr = ptr->next;
      ListNode *prev = head;
      while (ptr != NULL)
	{
	  if (ptr->item.compareTo(item) == EQUAL)
	    {
	      prev->next = ptr->next;
	      ptr = ptr->next;
	      return;
	    }
	  else
	    {
	      ptr = ptr->next;
	      prev = prev->next;
	    }
	}
    }
  std::cout << "Item not found." << std::endl;
}

int SortedLinkedList::searchItem(ItemType item)
{
  int count = -1;
  ListNode *ptr = head;
  while (ptr != NULL)
    {
      count ++;
      if (ptr->item.compareTo(item) == EQUAL)
	{
	  return count;
	}
      ptr = ptr->next;
    }
  std::cout << "Item not found." << std::endl;
  return -1;
}

//Will iterate through the list if possible, and if not will give the appropriate ItemType object to
//return for error-calling purposes
ItemType SortedLinkedList::getNextItem()
{
  ItemType empty;
  empty.initialize(-1);
  ItemType end;
  end.initialize(-2);
  if (head == NULL)
    {
      return empty;
    }
  else if (currentPos == NULL)
    {
      return end;
    }
  else
    {
      ListNode *temp = currentPos;
      currentPos = currentPos->next;
      return temp->item;
    }
}

//Will reset currentPos back to the head of the list
void SortedLinkedList::resetList()
{
  currentPos = head;
}

//Prints to standard output every data member of the given list.
void SortedLinkedList::printList()
{
  ListNode *temp = head;
  while (temp != NULL)
    {
      std::cout << temp->item.getValue() << " ";
      temp = temp->next;
    }
  std::cout << std::endl;
}
