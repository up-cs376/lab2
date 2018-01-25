#include <stdio.h>
#include <string.h>
#include "sort.h"

// A function that sorts three arrays (given, surname, year), according
// to the order of the given array.
//
// Uses bubblesort, which shows an example of a bad sorting algorithm
void sortByGiven(char* given[], char* surname[], int year[], int recordCount)
{
  // index into array we're currently looking at
  int idx;

  // boolean that tells whether the current iteration has done any
  // swapps
  int swapped = 1;

  // keep doing iterations until we see an iteration with no swaps
  while (swapped == 1) {

    // mark current iteration as "no swaps seen yet"
    swapped = 0;

    // loop through each pair of elements, swapping consecutive
    // elements if they're out of order
    for (idx = 1; idx < recordCount; idx++) {
      if (strcmp(given[idx], given[idx-1]) < 0) {
	// found two out-of-order elements: swap all three swaps

	char* tmpStr;
	int tmpInt;
	
	// swap given name
	tmpStr = given[idx];
	given[idx] = given[idx-1];
	given[idx-1] = tmpStr;
	
	// swap surname
	tmpStr = surname[idx];
	surname[idx] = surname[idx-1];
	surname[idx-1] = tmpStr;
	
	// swap hire year
	tmpInt = year[idx];
	year[idx] = year[idx-1];
	year[idx-1] = tmpInt;
	
	// mark that a swap has happened
	swapped = 1;
      }
    }
  }
}

// prints a record, consisting of a given name and surname
void printRecord(char* given, char* surname) {
  printf("%s %s\n", given, surname);
}
