#include <cstddef>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include "Sorting.h"

using namespace std;

//Finds the index of the minimum of the array. Used with selectionSort
int minIndex(int values[], int start, int end, long& comparisons)
{
  int indexOfMin = start;
  for (int index = start + 1; index <= end; index ++)
    {
      if (values[index] < values[indexOfMin])
	{
	  indexOfMin = index;
	}
      comparisons ++;
    }
  return indexOfMin;
}

//Runs a selection sort algorithm
long selectionSort(int values[], int numValues)
{
  long comparisons = 0;
  int endIndex = numValues - 1;
  for(int current = 0; current < endIndex; current ++)
    {
      swap(values[current], values[minIndex(values, current, endIndex, comparisons)]);
    }
  return comparisons;
}

//recursively splits the array into 2, then splits those two arrays into 2, etc. sorts, them, then recombins them into a fully sorted array.
//Used with mergeSort
void merge(int values[], int leftFirst, int leftLast, int rightFirst, int rightLast, long& comparisons)
{
  int tempArray[100000];
  int index = leftFirst;
  int saveFirst = leftFirst;

  while((leftFirst <= leftLast) && (rightFirst <= rightLast))
    {
      if (values[leftFirst] < values[rightFirst])
	{
	  tempArray[index] = values[leftFirst];
	  leftFirst ++;
	}
      else
	{
	  tempArray[index] = values[rightFirst];
	  rightFirst ++;
	}
      comparisons ++;
      index ++;
    }

  while (leftFirst <= leftLast)
    {
      tempArray[index] = values[leftFirst];
      leftFirst ++;
      index ++;
    }

  while (rightFirst <= rightLast)
    {
      tempArray[index] = values[rightFirst];
      rightFirst ++;
      index ++;
    }

  for (index = saveFirst; index <= rightLast; index ++)
    {
      values[index] = tempArray[index];
    }
}

//Runs the merge sort algorithm
void mergeSort(int values[], int first, int last, long& comparisons)
{
  if (first < last)
    {
      int middle = (first + last) / 2;
      mergeSort(values, first, middle, comparisons);
      mergeSort(values, middle + 1, last, comparisons);
      merge(values, first, middle, middle + 1, last, comparisons);
    }
}

//Recursively splits the array based around a given pivot and sorts the data within each split.
//This split is used for when the pivot is to be set to the first element, to be used with quickSortFP
void splitFP(int values[], int first, int last, int& splitPoint, long& comparisons)
{
  int splitVal = values[first];
  int saveFirst = first;
  bool onCorrectSide;
  first ++;
  do
    {
      onCorrectSide = true;
      while (onCorrectSide)
	{
	  if (values[first] > splitVal)
	    {
	      onCorrectSide = false;
	    }
	  else
	    {
	      first ++;
	      onCorrectSide = (first <= last);
	    }
	  comparisons ++;
	}
      onCorrectSide = (first <= last);
      while (onCorrectSide)
	{
	  if (values[last] <= splitVal)
	    {
	      onCorrectSide = false;
	    }
	  else
	    {
	      last --;
	      onCorrectSide = (first <= last);
	    }
	  comparisons ++;
	}
      if (first < last)
	{
	  swap(values[first], values[last]);
	  first ++;
	  last --;
	}
    } while (first <= last);
  splitPoint = last;
  swap(values[saveFirst], values[splitPoint]);
}

//Runs the quick sort algorithm with pivot set the beginning of each split array
void quickSortFP(int values[], int first, int last, long& comparisons)
{
  if (first < last)
    {
      int splitPoint;
      splitFP(values, first, last, splitPoint, comparisons);
      quickSortFP(values, first, splitPoint - 1, comparisons);
      quickSortFP(values, splitPoint + 1, last, comparisons);
    }
}

//This split is used for when the pivot is to be set to the first element, to be used with quickSortRP
void splitRP(int values[], int first, int last, int& splitPoint, long& comparisons)
{
  srand (time(NULL));
  int random = rand() % ((last - first) + 1) + first;
  int splitVal = values[random];
  int saveFirst = first;
  bool onCorrectSide;
  first ++;
  do
    {
      onCorrectSide = true;
      while (onCorrectSide)
	{
	  if (values[first] > splitVal)
	    {
	      onCorrectSide = false;
	    }
	  else
	    {
	      first ++;
	      onCorrectSide = (first <= last);
	    }
	  comparisons ++;
	}
      onCorrectSide = (first <= last);
      while (onCorrectSide)
	{
	  if (values[last] <= splitVal)
	    {
	      onCorrectSide = false;
	    }
	  else
	    {
	      last --;
	      onCorrectSide = (first <= last);
	    }
	  comparisons ++;
	}
      if (first < last)
	{
	  swap(values[first], values[last]);
	  first ++;
	  last --;
	}
    } while (first <= last);
  splitPoint = last;
  swap(values[saveFirst], values[splitPoint]);
}

//Runs the quick sort algorithm with pivot set a random element of each split array
void quickSortRP(int values[], int first, int last, long& comparisons)
{
  if (first < last)
    {
      int splitPoint;
      splitRP(values, first, last, splitPoint, comparisons);
      quickSortRP(values, first, splitPoint - 1, comparisons);
      quickSortRP(values, splitPoint + 1, last, comparisons);
    }
}

//Sorts the array by simulating a heap structure. Swaps the root with the child node with the largest value.
//Used with heapSort
void reheapDown(int values[], int root, int bottom, long& comparisons)
{
  int maxChild;
  int rightChild;
  int leftChild;

  leftChild = root * 2 + 1;
  rightChild = root * 2 + 2;
  if (leftChild <= bottom)
    {
      if(leftChild == bottom)
	{
	  maxChild = leftChild;
	}
      else
	{
	  if (values[leftChild] <= values[rightChild])
	    {
	      maxChild = rightChild;
	      comparisons ++;
	    }
	  else
	    {
	      maxChild = leftChild;
	      comparisons ++;
	    }
	}
      if (values[root] < values[maxChild])
	{
	  swap(values[root], values[maxChild]);
	  comparisons ++;
	  reheapDown(values, maxChild, bottom, comparisons);
	}
    }
}

//Runs a heap sort algorithm
long heapSort(int values[], int numValues)
{
  long comparisons = 0;
  int index;
  for (index = numValues/2 -1; index >= 0; index --)
    {
      reheapDown(values, index, numValues - 1, comparisons);
    }
  for (index = numValues - 1; index >= 1; index --)
    {
      swap(values[0], values[index]);
      reheapDown(values, 0, index - 1, comparisons);
    }
  return comparisons;
}
