#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>  
#include <cstdio>
#include "Sorting.h"

using namespace std;

int main(int argc, char *argv[])
{
  //Prompt and getting user input
  cout << "selection-sort (s) merge-sort (m) heap-sort (h) quick-sort-fp (q) quick-sort-rp (r)" << endl;
  cout << "Enter the algorithm: ";
  char algorithm;
  cin >> algorithm;
  cout << "Enter size of data set: ";
  int valSize;
  cin >> valSize;
  int values[valSize];
  long comparisons;

  srand (time(NULL));
  //Putting a random integer in each array index
  for (int i = 0; i < valSize; i ++)
    {
      int random = rand();
      values[i] = random;
    }
  for (int i = 0; i < valSize; i ++)
    {
      cout << values[i] << endl;
    }

  switch (algorithm)
    {
    case 's':
      {
	//Selection sort
	comparisons = selectionSort(values, valSize);
	cout << "1 2 3 4 5 ............ . . 9999" << endl;
	cout << "Array size: " << valSize << endl;
	cout << "\tSelection-sort comparisons: " << comparisons << endl;
	break;
      }
    case 'm':
      {
	//Merge sort
	comparisons = 0;
	mergeSort(values, 0, valSize, comparisons);
	cout << "1 2 3 4 5 ............ . . 9999" << endl;
	cout << "Array size: " << valSize << endl;
	cout << "\tMerge-sort comparisons: " << comparisons << endl;
	break;
      }
    case 'h':
      {
	//Heap sort
	comparisons = heapSort(values, valSize);
	cout << "1 2 3 4 5 ............ . . 9999" << endl;
	cout << "Array size: " << valSize << endl;
	cout << "\tHeap-sort comparisons: " << comparisons << endl;
	break;
      }
    case 'q':
      {
	//Quick sort with pivot set to first element of array
	comparisons = 0;
	quickSortFP(values, 0, valSize, comparisons);
	cout << "1 2 3 4 5 ............ . . 9999" << endl;
	cout << "Array size: " << valSize << endl;
	cout << "\tQuick-sort-fp comparisons: " << comparisons << endl;
	break;
      }
    case 'r':
      {
	//Quick sort with pivot set to a random element in the array
	comparisons = 0;
	quickSortRP(values, 0, valSize, comparisons);
	cout << "1 2 3 4 5 ............ . . 9999" << endl;
	cout << "Array size: " << valSize << endl;
	cout << "\tQuick-sort-rp comparisons: " << comparisons << endl;
	break;
      }
    default:
      cout << "Please enter a valid command. Exiting..." << endl;
      break;
    }
}
