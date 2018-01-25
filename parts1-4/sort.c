#include <string.h>
#include "sort.h"

// Implements the sort function, which performs selection sort 
// on an array of char*

// Function: sort (using selection sort algorithm)
//
// parameters:
//  - arr: an array of strings to be sorted
//  - length: the length of the array
void sort(char *arr[], int length) {
  // index variables
  int i, j;

  // outer loop: iteratively finds the next-smallest element and
  // puts it into the proper place
  for (i = 0; i < length; i++) {

    // inner loop: find the smallest element in the array from i to the end
    int smallIdx = i; // index of smallest element found so far
    for (j = i+1; j < length; j++) {
      if (strcmp(arr[j], arr[smallIdx]) < 0) {
	// found "smaller" string: update index
	smallIdx = j;
      }
    }

    // swap element currently at i with smallest element found
    char *temp = arr[smallIdx];
    arr[smallIdx] = arr[i];
    arr[i] = temp;
  }
}
