#include <stdio.h>
#include <string.h>

// Prints the names of people in a list, with a question mark after
// a specified name.
//
// to run the program, give a command such as:
//   mark_name 5
// It should should print
//   Billy Griffin
//   Mary Nicholas
//   Percy Smith
//   Zach Lewis
//   Amanda Kearney
//   Jill Simpson?
//   Ben Booker
//   Marcus Burns
//   Peter Monroe
//   Samantha Luchterhand
// with a '?' being placed after Jill Simpson (name #5, where counting
// starts with 0)

// the main method
int main(int argc, char* argv[])
{

  // 10 string (array of char) variables
  char name1[] = "Billy Griffin";
  char name2[] = "Mary Nicholas";
  char name3[] = "Percy Smith";
  char name4[] = "Zach Lewis";
  char name5[] = "Amanda Kearney";
  char name6[] = "Jill Simpson";
  char name7[] = "Ben Booker";
  char name8[] = "Marcus Burns";
  char name9[] = "Peter Monroe";
  char name10[] = "Samantha Luchterhand";

  int recordNum; // the record number
  int curRecord; // index of current record
  int recordCount = 10; // the number of records

  // array of strings, containing people's names
  char* name[10];

  // initialize the arrays witht he strings
  name[0] = name1;
  name[1] = name2;
  name[2] = name3;
  name[3] = name4;
  name[4] = name5;
  name[5] = name6;
  name[6] = name7;
  name[7] = name8;
  name[8] = name9;
  name[9] = name10;

  // if there is not exactly one argument (besides the command name),
  // give an error message and return
  if (argc != 2) {
    printf("ERROR: You need to provide a number.\n");
    return 1; // error
  }

  // convert the argument to an integer
  recordNum = atoi(argv[1]);

  // give error message if index is out of bounds
  if (recordNum < 0 || recordNum >= recordCount) {
    printf("Error: you gave an out-of-bounds record number\n");
    return 1;
  }

  // add a '?' to the end of the selected record's string
  char* theName = name[recordNum];
  int len = strlen(theName);
  theName[len] = '?';

  // print all the names
  printf("Names:\n");
  for (curRecord = 0; curRecord < recordCount; curRecord++) {
    printf("  %s\n", name[curRecord]);
  }
  
  // return "success"
  return 0;
}
