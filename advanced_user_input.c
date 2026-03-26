/*  Author: Rachal Thornton
*   Date: 3/26/26
*   Desc:  A program to model advanced input handling for a hangman game.
*   Notes:  Baisc input works
*           Letter and only 1 character validity works 
*           Need to store letter in array of max 26 and check for repeat letters */

/* Preprocessor Directives */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Definitions/Macros */
#define ALPHABET 26

/* Main */
int main(void) {
    /* Variables */
    char buff[10];                  /* Small buffer for fgets user input */
    char letter_guess;              /* Current letter user has guessed */
    char guessed_letters[ALPHABET]; /* Array of letters that user has previously guessed */

    /* Prompt for user input */
    printf("Enter a character: ");
    
    /* Using fgets to read user keyboard */
    if (fgets(buff, sizeof(buff), stdin) != NULL) {
        /* Check that user actually entered something, and only 1 letter */
        if (buff[0] != '\n' && buff[1] == '\n') {
            /* Change guess to all lowercase for future input validity */
            letter_guess = tolower(buff[0]);
            
            /* Check that user entered a char, not anything else */
            if (isalpha(letter_guess)) {
                printf("You guessed the letter: %c\n", letter_guess);
            } else {
                /* Error message to print when user enters something other than a char */
                printf("Not a valid guess! Please enter a character.\n");
            }
        } else {
            /* Error message to print when user enters more than 1 char */
            printf("Not a valid guess! Please enter exactly 1 character.\n");
        }
    }

    return 0;
}