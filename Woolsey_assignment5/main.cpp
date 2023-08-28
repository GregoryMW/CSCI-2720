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
  //Making sure only 1 inpupt file is given
  if (argc != 2)
    {
      cout << "Please give one input text file." << endl;
      return EXIT_FAILURE;
    }

  //Creation of the inital array. Takes in the numbers given from the file
  int values[10000];
  int valCount = 0;
  ifstream txtFile;
  string str;
  txtFile.open(argv[1]);
  while (getline(txtFile, str))
    {
      stringstream ss(str);
      int temp;
      while (ss >> temp)
	{
	  values[valCount] = temp;
	  valCount ++;
	}
    }
  txtFile.close();

  cout << "selection-sort (s) merge-sort (m) heap-sort (h) quick-sort-fp (q) quick-sort-rp (r)" << endl;
  cout << "Enter the algorithm: ";
  char input;
  cin >> input;
  long comparisons;
  //Take in the user input, and runs the appropriate sorting algorithm

  for (int i = 0; i < 10000; i ++)
    {
      cout << values[i] << endl;
    }
  
  switch (input)
    {
    case 's':
      {
	//Selection sort
	comparisons = selectionSort(values, 10000);
	cout << "\tSelection-sort comparisons: " << comparisons << endl;
	break;
      }
    case 'm':
      {
	//Merge sort
	comparisons = 0;
	mergeSort(values, 0, 10000, comparisons);
	cout << "\tMerge-sort comparisons: " << comparisons << endl;
	break;
      }
    case 'h':
      {
	//Heap sort
	comparisons = heapSort(values, 10000);
	cout << "\tHeap-sort comparisons: " << comparisons << endl;
	break;
      }
    case 'q':
      {
	//Quick sort with pivot set to first element of array
	comparisons = 0;
	quickSortFP(values, 0, 10000, comparisons);
	cout << "\tQuick-sort-fp comparisons: " << comparisons << endl;
	break;
      }
    case 'r':
      {
	//Quick sort with pivot set to a random element in the array
	comparisons = 0;
	quickSortRP(values, 0, 10000, comparisons);
	cout << "\tQuick-sort-rp comparisons: " << comparisons << endl;
	break;
      }
    default:
      cout << "Please enter a valid command. Exiting..." << endl;
      break;
    }
  return EXIT_SUCCESS;
}
