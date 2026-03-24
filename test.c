/*  Author: Rachal Thornton
*   Date: 3/24/26
*   Desc:  A short program to test out any features to be implemented into the final project.
*   Notes:  */

/* Preprocessor Directives */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Main */
int main(void) {
    /* Using fgets to check user input */
    char buff[10];
    char letter_guess;
    printf("Enter a character: ");
    
    if (fgets(buff, sizeof(buff), stdin) != NULL) {
        if (buff[0] != '\n' && buff[1] == '\n') {
            letter_guess = tolower(buff[0]);
            if (isalpha(letter_guess)) {
                printf("You guessed the letter: %c\n", letter_guess);
            } else {
                printf("Not a valid guess! Please enter a character.\n");
            }
        } else {
            printf("Not a valid guess! Please enter exactly 1 character.\n");
        }
    }

    return 0;
}