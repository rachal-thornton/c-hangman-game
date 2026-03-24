/*  Author: Rachal Thornton
*   Date: 3/24/26
*   Desc: A short program to model basic input handling for a hangman game. 
*   Notes: Basic input works
*          May need to change the scanf to fgets to ensure user only enters 1 char 
*          Will need to store all guesses in char array and loop through it to check if already char has already been guessed */

/* Preprocessor Directives */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Main */
int main(void) {
    /* Prompt user for their guess */
    printf("Enter your guess: \n");

    /* Read user input and store it in a char letter_guess, change letter_guess to lowercase */
    char letter_guess;
    scanf(" %c", &letter_guess);
    letter_guess = tolower(letter_guess);

    /* Basic user input validation and constraint checks */
    /* Check if letter_guess is a char */
    if(!isalpha(letter_guess)) {
        printf("Not a valid guess! Please enter a character.\n");
    
        /* Check if letter_guess is exactly 1 letter */
        /* Note: This doesn't work at the moment */
    } else if(strlen(&letter_guess) != 1) {
        printf("Not a valid guess! Please enter exactly 1 character.");
    
        /* If letter_guess is valid, accept it */
    } else {
        printf("You guessed the letter: %c\n", letter_guess);
    }
    
    return 0;
}


