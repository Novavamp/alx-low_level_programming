#include <stdlib.h>
#include <string.h>

int count_words(char *str);
char **strtow(char *str);

/**
 * count_words - Counts the number of words in a string
 * @str: Input string
 *
 * Return: Number of words
 */
int count_words(char *str)
{
	int count = 0;
	int i, len = strlen(str);

	for (i = 0; i < len; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
	}

	return count;
}

/**
 * strtow - Splits a string into words
 * @str: Input string
 *
 * Return: Pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	if (str == NULL || *str == '\0')
		return NULL;

	int num_words = count_words(str);
	if (num_words == 0)
		return NULL;

	char **words = malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
		return NULL;

	int i, j, k = 0, len = strlen(str), word_len;

	for (i = 0; i < len; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			word_len = 0;
			for (j = i; j < len && str[j] != ' '; j++)
				word_len++;

			words[k] = malloc((word_len + 1) * sizeof(char));
			if (words[k] == NULL)
			{
				for (i = 0; i < k; i++)
					free(words[i]);
				free(words);
				return NULL;
			}

			for (j = i; j < i + word_len; j++)
				words[k][j - i] = str[j];
			words[k][word_len] = '\0';
			k++;
		}
	}

	words[k] = NULL;
	return words;
}

