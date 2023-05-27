#include "shell.h"

/**
*check_delim - This function checks if a charater
*entered by the user matches any character
*@c: pointer to the address of charcter to be check
*@sf: pointer to the address of the array of delimiters
*Return: 1 if success, 0 if fail
*/
unsigned int check_delim(char c, const char *sf)
{
	unsigned int i;

	for (i = 0; sf[i] != '\0'; i++)
	{
		if (c == sf[i])
			return (1);
	}
	return (0);
}
