#include "shell.h"

/**
*this_ent - funtion that put string on enw line
*@stri: pointer to the address of string to be put on new line
*Return: no String
*/
char *this_ent(char *stri)
{

	free(sri);
	return ("\0");
}
/**
*this_space - this remove whitespace in string
*after it is call
*@stri: string to be edited
*Return: Returns the edited string
*/

char *this_space(char *stri)
{
	int i, j = 0;
	char *tmp;

	tmp = malloc(sizeof(char) * (this_strlen(sf) + 1));

	if (tmp == NULL)
	{
		free(tmp);
		return (NULL);
	}

	for (i = 0; sf[i] == ' '; i++)
		;
	for (; sf[i + 1] != '\0'; i++)
	{
		tmp[j] = sf[i];
		j++;
	}
	tmp[j] = '\0';

	if (tmp[0] == '\0' || tmp[0] == '#')
	{
		free(tmp);
		return ("\0");
	}
	return (tmp);

}
/**
*this_hash - this function deletes evrything after a '#'
*@tmp: pointer to the insert buffer
*Return: none
*/
void this_hash(char *tmp)
{
	int i;

	for (i = 0; tmp[i] != '\0'; i++)
	{
		if (tmp[i] == '#' && tmp[i - 1] == ' ' && tmp[i + 1] == ' ')
		{
			tmp[i] = '\0';
		}
	}
}
