/*  Author: Rachal Thornton
*   Date: 3/27/26
*   Desc:  A program to model a rough mock up of a hangman game to test seperate functions.
*   Notes:   */

/* Preprocessor Directives */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/* Function Prototypes */


/* Definitions/Macros */
#define ALPHABET 26
#define MAX_LIVES 6

/* Main */
int main (void) {
    /* Variables */
    bool is_running = true;

    /* Main game loop */
    while (is_running) {
        printf("Welcome to Hangman!\n");
        printf("Do you want to play? (y/n)\n");
        char is_playing;
        scanf(" %c", &is_playing);

        /* User wants to quit */
        if(tolower(is_playing) == 'n') {
            printf("Thanks for playing!\n");
            return 0;

            /* User wants to play*/
        } else if (tolower(is_playing) == 'y') {
            /* Set word; Display UI */
            int lives = 0;
            int num_letters = 0;
            char curr_letter;
            char guessed_letters[ALPHABET];

            /* Loop to guess letters while user still has lives left */
            while(lives < MAX_LIVES) {
                /* Valid guess */
                if(getLetter(&curr_letter, &num_letters, &guessed_letters) == 0) {
                    printf("You guessed letter: %c\n", curr_letter);

                    /* Invalid guess */
                } else {
                    printf("Invalid guess, please try again!\n");
                    continue;
                }
            }

            /* User runs out of lives; loses */
            printf("You lost!\n");
            is_running = false;

            /* User inputs something else */
        } else {
            continue;
        }
    }
    return 0;
}

/* getLetter function 
*  Pre: input is passed into function from main
*  Post: validates that input is a single letter and has not been guessed, then stores guess in char array 
*        returns 0 if valid, 1 if not */
int getLetter(char *curr_letter, int *num_letters, char *guessed_letters[ALPHABET]) {
    /* Variables */
    char buff[10];

    /* Check that user actually entered something, and only 1 letter */
    if(fgets(buff, sizeof(buff), stdin) != NULL) {
        if(buff[0] != '\n' && buff[1] == '\n') {
            /* Convert to lowercase */
            *curr_letter = tolower(buff[0]);

            /* Check that user entered a char, not anything else */
            if(isalpha(*curr_letter)) {
                /* Check that user has not guessed the letter before */
                int i;
                for(i = 0; i < *num_letters; i++) {
                    if(*curr_letter == guessed_letters[i]) {
                        printf("You've already guessed that letter! Try again.\n");
                        return -1;
                    }
                }
            }
        }
    }
}
