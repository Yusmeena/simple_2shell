#include "shell.h"

/**
*check_delim - this function checks if a charater 
* enter matches any character
*@c: pointer to the address of charcter to be check
*@str: pointer to the address of the array of delimiters
*Return: 1 if success, 0 if fail
*/
unsigned int check_delim(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++}
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}
