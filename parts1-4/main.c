#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

// main program: sorts and prints an array

// number of elements in the array
#define NUMBER_OF_NAMES 11

// the array to sort
char* names[NUMBER_OF_NAMES] = {
  "John",
  "Sam",
  "Marie",
  "Ben",
  "Brittany",
  "Sarah",
  "Walter",
  "Wanda",
  "Jane",
  "Annika",
  "Peter",
};

// a (private) function to print a line of "=" characters
static void printSeparatorLine() {
  printf("================================================================\n");
}

// our main function
//
// - returns: the exit status of the program
int main(void) {
  // index variable for for-loop
  int i;

  // sort the array
  sort(names, NUMBER_OF_NAMES);

  // print each element of the array
  for (i = 0; i < NUMBER_OF_NAMES; i++) {
    printf("%s\n", names[i]);
  }

  // return with "success" status
  return EXIT_SUCCESS;
}
