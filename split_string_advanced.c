#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **splitString(const char *str, const char *delimiter, int *count)
{
	/* Calculate the number of words in the string*/
	int numWords = 1; /*At least one word*/
	const char *ptr = str;
	while (*ptr)
	{
		if (strchr(delimiter, *ptr))
		{
			/*Found a delimiter*/
			numWords++;
		}
		ptr++;
	}

	/*Allocate memory for the array of words*/
	char **words = (char **)malloc(numWords * sizeof(char *));
	if (!words)
	{
		printf("Memory allocation failed.\n");
		*count = 0;
		return (NULL);
	}

	int index = 0;
	int wordStart = 0;
	int wordLength = 0;
	for (int i = 0; i <= strlen(str); i++)
	{
		if (strchr(delimiter, str[i]) || str[i] == '\0')
		{
			/*Found a delimiter or end of string*/
			wordLength = i - wordStart;

			/*Allocate memory for the word and copy it*/
			words[index] = (char *)malloc((wordLength + 1) * sizeof(char));
			strncpy(words[index], &str[wordStart], wordLength);
			words[index][wordLength] = '\0';

			index++;
			wordStart = i + 1;
		}
	}

	*count = numWords;
	return (words);
}

int main(void)
{
	const char *str = "This is a sample string.";
	const char *delimiter = " ";
	int count = 0;
	char **words = splitString(str, delimiter, &count);

	if (words)
	{
		printf("Number of words: %d\n", count);
		for (int i = 0; i < count; i++)
		{
			printf("Word %d: %s\n", i + 1, words[i]);
			free(words[i]);
		}
		free(words);
	}

	return (0);
}
