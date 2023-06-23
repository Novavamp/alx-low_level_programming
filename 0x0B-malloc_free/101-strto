#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Returns the number of words in the given string */
int count_words(char *str) {
    int count = 0;
    int in_word = 0; /* indicates if we're currently in a word */

    while (*str != '\0') {
        if (!isspace(*str)) { /* current character is not whitespace */
            if (!in_word) { /* start of a new word */
                count++;
                in_word = 1;
            }
        } else { /* current character is whitespace */
            in_word = 0;
        }
        str++;
    }

    return count;
}

/* Splits the given string into words and returns an array of pointers to the words */
char **strtow(char *str) {
    int i, j;
    char **words;
    int num_words = count_words(str);

    /* Allocate memory for the array of word pointers */
    words = (char **) malloc((num_words + 1) * sizeof(char *));
    if (words == NULL) {
        return NULL; /* Memory allocation error */
    }

    /* Extract words from the string and store them in the array */
    for (i = 0; i < num_words; i++) {
        /* Find the start of the next word */
        while (isspace(*str)) {
            str++;
        }

        /* Find the end of the current word */
        for (j = 0; str[j] != '\0' && !isspace(str[j]); j++) {
        }

        /* Allocate memory for the word and copy it into the array */
        words[i] = (char *) malloc((j + 1) * sizeof(char));
        if (words[i] == NULL) {
            /* Memory allocation error, free previously allocated memory and return NULL */
            for (j = 0; j < i; j++) {
                free(words[j]);
            }
            free(words);
            return NULL;
        }
        strncpy(words[i], str, j);
        words[i][j] = '\0';

        /* Move to the start of the next word */
        str += j;
    }
    words[num_words] = NULL; /* Mark the end of the array with a NULL pointer */

    return words;
}

