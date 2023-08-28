#include <cstddef>
#include <iostream>
#include "DoublyLinkedList.h"

//Constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  head = NULL;
  tail = NULL;
}

//Destructor
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  NodeType<T> *temp = head;
  while (temp != NULL)
    {
      NodeType<T> *temp2 = temp->next;
      delete temp;
      temp = temp2;
    }
}

//Finds the appropriate position to place the given item in the list while keeping the list sorted.
//Updates any applicable linked nodes and the head and tail as needed.
template <class T>
void DoublyLinkedList<T>::insertItem(T &item)
{
  NodeType<T> *temp = new NodeType<T>;
  temp->data = item;
  temp->next = NULL;
  temp->back = NULL;
  if (head == NULL)
    {
      head = new NodeType<T>;
      head->data = temp->data;
      head->next = temp->next;
      head->back = temp->back;
      tail = new NodeType<T>;
      tail->data = temp->data;
      tail->next = temp->next;
      tail->back = temp->back;
    }
  else
    {
      NodeType<T> *ptr = head;
      while (ptr != NULL)
	{
	  if (temp->data < ptr->data)
	  {
	    if (ptr == head)
	      {
		temp->next = ptr;
		temp->back = NULL;
		ptr->back = temp;
		head = temp;
		return;
	      }
	    else
	      {
		temp->next = ptr;
		temp->back = ptr->back;
		ptr->back->next = temp;
		ptr->back = temp;
		return;
	      }
	  }
	  else if (temp->data == ptr->data)
	    {
	      if (ptr->next == NULL)
		{
		  temp->next = NULL;
		  temp->back = ptr;
		  ptr->next = temp;
		  tail = temp;
		  return;
		}
	      else if (ptr->back == NULL)
		{
		  temp->next = ptr;
		  temp->back = NULL;
		  ptr->back = temp;
		  head = temp;
		  return;
		}
	      else
		{
		  temp->next = ptr;
		  temp->back = ptr->back;
		  ptr->back->next = temp;
		  ptr->back = temp;
		  return;
		}
	    }
	  else
	    {
	      if (ptr->next == NULL)
		{
		  temp->next = NULL;
		  temp->back = ptr;
		  ptr->next = temp;
		  tail = temp;
		  return;
		}
	      else if (temp->data < ptr->next->data)
		{
		  temp->next = ptr->next;
		  temp->back = ptr;
		  ptr->next->back = temp;
		  ptr->next = temp;
		  return;
		}
	      ptr = ptr->next;
	    }
	}
    }
}

//Searches through the list and finds the given item to delete, making sure to
//update any linked nodes as well as the head and tail as needed.
template <class T>
void DoublyLinkedList<T>::deleteItem(T &item)
{
  NodeType<T> *ptr = head;
  if (head == NULL)
    {
      std::cout << "You cannot delete from an empty list." << std::endl;
      return;
    }
  else if (head->next == NULL && head->back == NULL)
    {
      if (ptr->data == item)
	{
	  head = NULL;
	  tail = NULL;
	  return;
	}
    }
  else
    {
      if (ptr->data == item)
	{
	  ptr->next->back = NULL;
	  head = ptr->next;
	  return;
	}
      ptr = ptr->next;
      while (ptr != NULL)
	{
	  if (ptr->data == item)
	    {
	      if (ptr->next == NULL)
		{
		  ptr->back->next = ptr->next;
		  tail = ptr->back;
		  return;
		}
	      else
		{
		  ptr->back->next = ptr->next;
		  ptr->next->back = ptr->back;
		  return;
		}
	    }
	  else
	    {
	      ptr = ptr->next;
	    }
	}
    }
  std::cout << "Item not found." << std::endl;
}

//Returns the length of the list
template <class T>
int DoublyLinkedList<T>::lengthIs() const
{
  int count = 0;
  NodeType<T> *ptr = head;
  while (ptr != NULL)
    {
      count ++;
      ptr = ptr->next;
    }
  return count;
}

//Prints the list in sorted order
template <class T>
void DoublyLinkedList<T>::print()
{
  NodeType<T> *ptr = head;
  while (ptr != NULL)
    {
      std::cout << ptr->data << " ";
      ptr = ptr->next;
    }
  std::cout << std::endl;
}

//Prints the list in reverse sorted order, starting from the end
template <class T>
void DoublyLinkedList<T>::printReverse()
{
  NodeType<T> *ptr = tail;
  while (ptr != NULL)
    {
      std::cout << ptr->data << " ";
      ptr = ptr->back;
    }
  std::cout << std::endl;
}

//Takes in two values to use as bounds and searches for and deletes any values within the range
template <class T>
void DoublyLinkedList<T>::deleteSubsection(T &start, T &end)
{
  NodeType<T> *ptr = head;
  if (head == NULL)
    {
      return;
    }
  else if (head->next == NULL && head->back == NULL)
    {
      if (ptr->data >= start && ptr->data <= end)
	{
	  head = NULL;
	  tail = NULL;
	  return;
	}
    }
  else
    {
      while (ptr != NULL)
	{
	  NodeType<T> *headTemp = head;
	  if (headTemp->data >= start && headTemp->data <= end)
	    {
	      if (headTemp->next == NULL)
		{
		  headTemp = NULL;
		  head = headTemp;
		  tail = NULL;
		  ptr = head;
		}
	      else
		{
		  headTemp->next->back = NULL;
		  head = headTemp->next;
		  ptr = head;
		}
	    }
	  else if (ptr->data >= start && ptr->data <= end)
	    {
	      if (ptr->next == NULL)
		{
		  ptr->back->next = ptr->next;
		  tail = ptr->back;
		  ptr = ptr->next;
		}
	      else
		{
		  ptr->back->next = ptr->next;
		  ptr->next->back = ptr->back;
		  ptr = ptr->next;
		}
	    }
	  else
	    {
	      ptr = ptr->next;
	    }
	}
    }
}

//Goes through the list and counts how many times every value in the list appears. Then returns
//the value that appears the most in the current list.
template <class T>
T DoublyLinkedList<T>::mode()
{
  int valCount;
  T mode;
  int modeCount;

  NodeType<T> *checkVal;
  NodeType<T> *ptr;

  checkVal = head;
  mode = checkVal->data;
  modeCount = 0;
  while(checkVal != NULL)
    {
      valCount = 0;
      ptr = checkVal;
      while (ptr->next != NULL)
	{
	  ptr = ptr->next;
	  if (ptr->data == checkVal->data)
	    {
	      valCount++;
	    }
	}
      if (valCount > modeCount)
	{
	  mode = checkVal->data;
	  modeCount = valCount;
	}
      checkVal = checkVal->next;
    }
  return mode;
}

//This will swap every two nodes in the list using pointers instead of swapping the individual data values of the nodes.
template <class T>
void DoublyLinkedList<T>::swapAlternate()
{
  NodeType<T> *ptr = head;

  while(ptr->next != NULL)
    {
      NodeType<T> *swap1 = ptr;
      NodeType<T> *swap2 = ptr->next;
      int isHead = 0;
      int isTail = 0;
      if (ptr == head)
	isHead = 1;
      if (ptr->next == tail)
	isTail = 1;

      if (swap2->next != NULL)	
	  swap2->next->back = swap1;	
      if (swap1->back != NULL)	
	  swap1->back->next = swap2;	

      swap1->next = swap2->next;
      swap2->back = swap1->back;
      swap1->back = swap2;
      swap2->next = swap1;
      
      if (isHead)
	{
	  head = swap2;
	}
      if(isTail)
	{
	  tail = swap1;
	}
      ptr = ptr->next;
    }
}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;
