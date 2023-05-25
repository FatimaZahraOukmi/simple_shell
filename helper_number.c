#include "shell.h"

/**
 * long_to_string - convert a num to a str.
 *
 * @number: num to be convert in an str.
 *
 * @string: buffer to save the num as str.
 *
 * @base: base to convert num
 *
 * Return: Null
 */
void long_to_string(long number, char *string, int base)
{
	int index = 0, inNegative = 0;
	long cociente = number;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		string[index++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			string[index++] = letters[-(cociente % base)];
		else
			string[index++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		string[index++] = '-';

	string[index] = '\0';
	str_reverse(string);
}


/**
 * _atoi - convert a str to an int.
 *
 * @s: pointer to string  origen.
 *
 * Return: int  of str or 0.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int number = 0;
	/*1- analisys sign*/
	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		if (*s == '+')
			sign *= +1;
		s++;
	}

	/*2 - extract the num */
	while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		number = (number * 10) + (*s - '0');
		s++;
	}
	return (number * sign);
}

/**
 * count_characters - count the coincidences of character in str
 *
 * @string: pointer to string origen.
 *
 * @character: str with  characters to be counted
 *
 * Return: int of string  or 0.
 */
int count_characters(char *string, char *character)
{
	int i = 0, counter = 0;

	for (; string[i]; i++)
	{
		if (string[i] == character[0])
			counter++;
	}
	return (counter);
}
