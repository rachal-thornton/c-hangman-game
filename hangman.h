/*  Authors: Alyssa Schmidt, Rachal Thornton, Molly Westemeier
*   Due: 4/28/26
*   Desc: A header file for a hangman game in the hangman.c program file.
*   Notes: Function signatures subject to change */

#ifndef HANGMAN_H
#define HANGMAN_H

/* Definitions/Macros */
#define ALPHABET 26
#define MAX_LIVES 6
#define MAX_CHAR 12

/* Function Declarations */
void pickWord(const char *filename); /* Molly */
void hideWord(char *word, char *hideWord); /* Alyssa */
void prompt(); /* Rachal */
int validateGuess(char *curr_letter, int *num_letters, char guessed_letters[ALPHABET]); /* Rachal */
void update_(char guess,char* hiddenWord,char* word);
void loseLife(); 
void end();

#endif