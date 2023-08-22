#include "main.h"

/**
 * _strlen - count how many character in a string
 * @s: string character
 * Return: numbers of characters
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
	{
		len++;
	}

	return (len);
}
