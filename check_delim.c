#include "shell.h"

/**
*check_delim - This function checks if a charater
*entered by the user matches any character
*@k: pointer to the address of charcter to be check
*@stri: pointer to the address of the array of delimiters
*Return: 1 if success, 0 if fail
*/
unsigned int check_delim(char k, const char *stri)

	unsigned int i;

	for (i = 0; stri[i] != '\0'; i++)
	{
		if (k == stri[i])
			return (1);
	}
	return (0);
}
