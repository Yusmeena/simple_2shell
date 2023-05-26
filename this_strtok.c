#include "shell.h"

/**
*this_strtok - this function that gets token from a string
*@sf: pointer to the address of string
*@tk: pointer to the delimiter
*Return: pointer ro the address of next token or NULL if none
*/

char *this_strtok(char *sf, const *tk)
{
	static char *o, *c;
	unsigned int i;

	if (sf != NULL)
		c = sf;
	o = c;
	if (o == NULL)
		return (NULL);
	for (i = 0; c[i] != '\0'; i++)
	{
		if (check_delim(c[i], tk) == 0)
			break;
	}
	if (c[i] == '\0' || c[i] == '#')
	{
		c = NULL;
		return (NULL);
	}
	o = c + i;
	c = o;
	for (i = 0; c[i] != '\0'; i++)
	{
		if (check_delim(c[i], tk) == 1)
			break;
	}
	if (c[i] == '\0')
		c =NULL;
	else
	{
		c[i] = '\0';
		c = c + i + 1;

		if (*c == '\0')
			c = NULL;
	}
	return (o);
}
