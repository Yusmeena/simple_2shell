#include "main.h"

/**
* read_line - reads the input string. 
*
*@i_eo: return value of getline function
*Return: insert string
*/

char *read_line(int *readme)
{
	char *input = NULL;
	size_t bufsize = 0;

	*readme = getline(&input, &bufsize, stdin);

	return (input);
}
