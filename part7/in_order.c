#include <stdio.h>
#include "sort.h"

// Prints a list of employees, sorted by given (i.e., first) name.
//
// To run, give the command:
//   in_order
// It will print the sorted list of employees.

// prints a record, consisting of a given name and surname
void printRecord(char* given, char* surname) {
  printf("%s %s\n", given, surname);
}

// main function
int main(void) {

  // the array of given names
  char* given[] = {
      "Billy",
      "Mary",
      "Percy",
      "Zach",
      "Amanda",
      "Jill",
      "Ben",
      "Marcus",
      "Peter",
      "Samantha"
    };

  // the array of surnames
  char* surname[] = {
    "Griffin",
    "Smith",
    "Nicholas",
    "Lewis",
    "Kearney",
    "Simpson",
    "Booker",
    "Burns",
    "Monroe",
    "Luchterhand"
  };

  // the array of hire years
  int hire_year[] = {
    1998,
    2012,
    2013,
    2003,
    1983,
    2007,
    2005,
    1995,
    2000,
    2004
  };

  // the number of records represented in our arrays
  int recordCount = 10;

  // the index of the current record
  int curRecord;

  // sort the arrays
  sortGiven(given, surname, hire_year, recordCount);

  // print the records
  for (curRecord = 0; curRecord < recordCount; curRecord++) {
    printRecord(given[curRecord], surname[curRecord]);
  }

  // return "success"
  return 0;
}
