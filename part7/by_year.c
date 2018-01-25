#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Prints all employees who have been hired since the given year.
//
// To run the program give a command such as
//   by_year 2006
// It will print the employees who have been hired no earlier than 2006.


// the main function for our program
int main(int argc, char* argv[]) {

  // array of hire years
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
  
  // corresponding array of surnames (last names)
  char* surname[] = {
    "Douglas",
    "Jones",
    "Smith",
    "Doe",
    "Desmond",
    "Fyall",
    "Tuttle",
    "Bartholomew",
    "DeBudge"
  };

  // corresponding array of given (first) names
  char* given[] = {
    "Eva",
    "Joe",
    "John",
    "Jill",
    "Marcus",
    "Holly",
    "Michael",
    "Amanda",
    "Ben",
    "Andrea"
  };

  char *title = "Employee Lister";
  
  // the year, read from the command line
  int year = 0xffffffff;

  // the number of recorsd
  int recordCount = 10;

  // the current record
  int curRecord;
  
  // give error message and return unless there is exactly one argument
  // (in addition to the command name)
  if (argc != 2) {
    printf("ERROR: You need to provide exactly one year.\n");
    return 1; // error
  }
  else {
    // convert year-string to integer
    year = atoi(argv[1]);
  }
  
  // prints the employess hired during or since theh given year
  printf("%s\n", title);
  printf("The following people have been hired since %d (inclusive)...\n",
	 year);
  for (curRecord = 0; curRecord < recordCount; curRecord++) {
    if (hire_year[curRecord] >= year) {
      printf("[%d] %s %s\n", hire_year[curRecord], given[curRecord],
	     surname[curRecord]);
    }
  }
  
  // return "success"
  return 0;
}

