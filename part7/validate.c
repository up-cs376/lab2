#include <stdio.h>
#include <string.h>

// Program that determines whether a name is valid.
// A name is considered to be valid if all of the following are
// true:
// - its length is at least 5 letters
// - it contains at least one vowel
// - it contains at least one upper-case letter
//
// to run the program:
//   validate Crenshaw
// or, if the name has more than one part
//   validate 'John H. Hampton'

// tests whether a character is a vowel
int isVowel(char c) {
  // return 1 (true) if we have a vowel, otherwise 0 (false)
  switch (c) {
  case 'a': case 'e': case 'i': case 'o': case 'u':
  case 'A': case 'E': case 'I': case 'O': case 'U': 
    return 1;
  default:
    return 0;
  }
}

// tests whether a name contains a vowel
int hasVowel(char* name) {
  // loop through and look for a vowel; return 1 (true) if we find one
  int idx;
  for (idx = 0; idx < strlen(name); idx++) {
    if (isVowel(name[idx])) return 1;
  }

  // did not find vowel: return 0 (false)
  return 0;
}

// tells whether a name contains an upper-case letter
int hasUpper(char* name)
{
  // loop through and look for an upper-case letter; return 1 (true)
  // if we find one
  int idx;
  for (idx = 0; idx < strlen(name); idx++) {
    char c = name[idx];
    if (c >= 'A' && c <= 'Z') return 1;
  }

  // did not find one: return 0 (false)
  return 0;
}

// counts the letters in a name
int numLetters(char* name) {
  // counting variable
  int numLetters = 0;
  
  // loop through and count the letters
  int idx;
  for (idx = 0; idx < strlen(name); idx++) {
    // if it's a letter, bump the count
    char c = name[idx];
    if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') numLetters++;
  }
  
  // return the number of letters counted
  return numLetters;
}


// Determine if a name is valid.
// - If valid, silently returns a 1 (true)
// - If invalid, prints a message and returns 0 (false)
int validateName(char* name) {
  int letterCount = numLetters(name);
  
  // check if there is a vowel
  if (hasVowel(name) == 0) {
    printf("Try again. There aren't any vowels in: %s\n", name);
    return 0;
  }
  
  // check if there is an upper-case letter
  if (hasUpper(name) == 0) {
    printf("Try again. You should do yourself the courtesy of "
	   "capitalizing your name: %s\n",
	   name);
    return 0;
  }
  
  // check if the letter-count is at least 5
  if (letterCount < 5)  {
    printf("You expect me to believe your name (%s) only has %s "
	   "letters in it, do you?\n",
	   name, letterCount);
    return 0;
  }

  // if everything checks out, return 1 (true)
  return 1;
}

// main function for progra
int main(int argc, char* argv[]) {

  // check to ensure that there is exactly one argument (in addition
  // to the command name)
  if (argc != 2) {
    printf("Need exactly one argument.\n");
    return 1; // return error status
  }

  // set the name to be the first argument
  char* name = argv[1];

  // set 'insertString' to empty or " NOT", depending on validity of
  // name
  char* insertString = "";
  if (!validateName(name)) {
    insertString = " NOT";
  }
  
  // print the message, telling if name was valid
  printf("Name is%s valid.\n", insertString);

  // return success status
  return 0;
}

