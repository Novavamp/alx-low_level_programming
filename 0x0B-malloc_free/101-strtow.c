#include <main.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100 // maximum length of a word

// helper function to determine if a character is a whitespace character
int is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

char **strtow(char *str) {
    int i, j, k;
    int word_count = 0;
    char **words = NULL;

    // count the number of words in the string
    for (i = 0; str[i] != '\0'; i++) {
        if (!is_whitespace(str[i])) {
            word_count++;
            // skip the rest of the current word to avoid counting it again
            while (!is_whitespace(str[i]) && str[i] != '\0') {
                i++;
            }
        }
    }

    // allocate memory for the array of words
    words = (char **) malloc((word_count + 1) * sizeof(char *));
    if (words == NULL) {
        return NULL;
    }

    // extract the words from the string and store them in the array
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (!is_whitespace(str[i])) {
            // allocate memory for the current word
            words[j] = (char *) malloc((MAX_WORD_LEN + 1) * sizeof(char));
            if (words[j] == NULL) {
                // free previously allocated memory and return NULL on error
                for (k = 0; k < j; k++) {
                    free(words[k]);
                }
                free(words);
                return NULL;
            }

            // copy the characters of the current word into the allocated memory
            for (k = 0; !is_whitespace(str[i]) && str[i] != '\0'; i++, k++) {
                words[j][k] = str[i];
            }
            words[j][k] = '\0';

            j++;
        }
    }
    words[j] = NULL; // mark the end of the array with a NULL pointer

    return words;
}

