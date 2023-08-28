#ifndef SORTING_H
#define SORTING_H

int minIndex(int values[], int start, int end, long& comparisons);
long selectionSort(int values[], int numValues);
void merge(int values[], int leftFirst, int leftLast, int rightFirst, int rightLast, long& comparisons);
void mergeSort(int values[], int first, int last, long& comparisons);
void splitFP(int values[], int first, int last, int& splitPoint, long& comparisons);
void quickSortFP(int values[], int first, int last, long& comparisons);
void splitRP(int values[], int first, int last, int& splitPoint, long& comparisons);
void quickSortRP(int values[], int first, int last, long& comparisons);
void reheapDown(int values[], int root, int bottom);
long heapSort(int values[], int numValues);

#endif
