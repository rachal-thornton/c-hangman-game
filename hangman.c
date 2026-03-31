/*  Authors: Alyssa Schmidt, Rachal Thornton, Molly Westemeier
*   Due: 4/28/26
*   Desc: A program to model a rough mock up of a hangman game to test seperate functions.
*   Notes: Version 2.0 to test with group functions */

/* Preprocessor Directives */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

/* Header File */
#include "hangman.h"

/* Global Variables */
char word[7]; /* Chosen word */
int lives = MAX_LIVES; /* Number of lives left */
char guessed_letters[ALPHABET]; /* Array of letters that user has previously guessed */
int num_guessed_letters = 0; /* Number of letters that user has guessed */
char curr_letter; /* Current letter user has guessed */


/* Main Function */
int main(void) {
    /* Initialize random seed for word selection */
    srand(time(NULL));
    /* Pick a random word from text file */
    pickWord("words.txt");
    /* Print the chosen word */
    printf("Chosen word: %s\n", word);

    /* Hide the chosen word */
    char* hiddenWord = malloc(sizeof(char)*MAX_CHAR); 
    hideWord(word,hiddenWord); 

    /* Prints to make sure functions run correclty */
    printf("%s\n",word); 
    printf("%s\n",hiddenWord); 

    printf("Guess a letter: ");
    validateGuess(&curr_letter, &num_guessed_letters, guessed_letters);
    update_(curr_letter,hiddenWord,word);

    return 0;
}

/* pickWord function */
void pickWord(const char *filename) {
    FILE *fp;
    char temp[100];
    int count = 0;
    int targetLine, i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    /* count how many lines are in the file */
    while (fgets(temp, sizeof(temp), fp) != NULL) {
        count++;
    }

    if (count == 0) {
        printf("Error: file is empty\n");
        fclose(fp);
        exit(1);
    }

    /* pick a random line number */
    targetLine = rand() % count;

    /* go back to beginning of file */
    rewind(fp);

    /* read until the chosen line */
    for (i = 0; i <= targetLine; i++) {
        fgets(temp, sizeof(temp), fp);
    }

    /* remove newline if there is one */
    temp[strcspn(temp, "\n")] = '\0';

    /* copy chosen word into global word */
    strcpy(word, temp);

    fclose(fp);
}

/* hideWord function */
/*takes the address of the word to guess and the address for the hidden version */ 
/*places the word with non spaces swapped for underscores in the hideWord address */ 
void hideWord(char* word,char* hideWord){ 

    int i = 0; 

    int length = strlen(word); 

    memset(hideWord,'\0',MAX_CHAR);    /*set all character to end of string characters*/ 

    while(i < length){         /*check each character in the string if not a  */ 

        if(!isspace(word[i])){     /*space replace the character with a '_' */ 

            hideWord[i] = '_';   

        } 

        i++; 

    } 

}

/* prompt function 
* ask user to guess a letter, show underscores and hangman
*   Pre:
*   Post:*/
void prompt() {
    /* Prompt for user input */
    printf("Guess a letter: ");
}

/* validateGuess function 
*   Pre: input is passed into function from main
*   Post: validates that input is a single letter and has not been guessed, then stores guess in char array 
*        returns 0 if valid, 1 if not */
int validateGuess(char *curr_letter, int *num_letters, char guessed_letters[ALPHABET]) {
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
                /* User has guessed a new letter */
                printf("You guessed the letter: %c\n", *curr_letter);
                guessed_letters[i] = *curr_letter;
                (*num_letters)++;
            } else {
                /* Error message to print when user enters something other than a char */
                printf("Not a valid guess! Please enter a character.\n");
                return -1;
            }
        } else {
            /* Error message to print when user enters more than 1 char */
            printf("Not a valid guess! Please enter exactly 1 character.\n");
            return -1;
        }
    }
    return 0;
}

void update_(char guess,char* hiddenWord,char* word){
    printf("entered update_");
    int index;      /* index of the character */
    printf("index created\n");
    char *charFound = strchr(word,guess);
    printf("%s\n",charFound);
    index = charFound - word;
    printf("%d\n",index);

}
