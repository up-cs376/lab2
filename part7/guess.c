#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Selects a random number in the range 0..10. Then prompts user
// to guess the number. Continues asking for guesses until the
// user guesses the correct number.
//
// To run the program, give the command:
//   guess
// It will prompt you for guesses until you type in the correct number

// function prototypes
static int readIntegerFromKeyboard();
static int initRandom();

// performs main function for the program, allowing user to continue
// to guess numbrers
int main(void) {

  // the random value that user is trying to guess
  int value;

  // the current guess
  int guess;
  
  // generate a random number from 0-10
  initRandom();
  value = (rand() % 11);
  
  // keep asking the user for a guess until he/she guesses
  // correctly
  do {

    // read a number from the keyboard
    printf("Guess a value from 0 to 10: ");
    guess = readIntegerFromKeyboard();
    
    // print a message corresponding to the correctness of
    // the user's guess
    if (value = guess) {
      printf("Correct! %d was the number.\n", guess);
    }
    else if (value < guess) {
      printf("Nope. %d is too big.\n", guess);
    }
    else {
      printf("Nope. %d is too small.\n", guess);
    }
  }
  while  (guess != value);

  // return "success"
  return 0;
}

// helper-function to read a number from the keyboard
static int readIntegerFromKeyboard() {

  // keep attempting to read until a valid integer value is seen
  for (;;) {
    int val; // variable to hold the integer value types
    int count; // tells whether we read an integer value
    char c; // dummy character for used in skipping whitespace

    
    // read and (if successful) return the value read
    count = scanf("%d", &val); // try to read the value from the keyboard
    if (count > 0) return val;

    // could not read value; prompt again, skip whitespace
    printf("invalid number: please try again: \n");
    scanf("%*[ \n\t]%c",&c);
  }
}

// helper-function to initialize the random number generator
static int initRandom() {
  // make the appropriate library call
  srand((int)time(NULL));
}
