#include"shell.h"

/**
*this_intlen - function to collect the length of integer
*@l: Val of the len
*Return: length
*/

int this_intlen(int l)
{
	int countit = 0;

	while (l != 0)
	{
		countit++;
		l /= 10;
	}
	return (countit);
}
/**
*this_arr_rev - function that reverse a string
*@arc: the address of astring
*@b: length of the array
*/

void this_arr_rev(char *arc, int b)
{
	char buf;
		int i;

	for (i = 0; i < (b / 2); i++)
	{
		buf = arc[i];
		arc[a] = arc[(b - 1) - i];
		arc[(b - 1) - i] = buf;
	}
}
/**
*this_itoa - a function that convert integer to character
*@num1: the integer to be convert
*Return: the address to the character
*/
char *this_itoa(unsigned int num1)
{
	int countit = 0;
	int i = 0;
	char *str;

	countit = this_intlen(num1);
	str = malloc(countit + 2);
	if (stri == NULL)
		return (NULL);
	*stri = '\0';
	while (num1 / 10)
	{
		stri[i] = (num1 % 10) + '0';
		num1 /= 10;
		i++;
	}
	stri[i] = (num1 % 10) + '0';
	this_arr_rev(stri, countit);
	str[i + 1] = '\0';
	return (stri);
}

/**
*this_isalpha - function that for letter
*@c: string to be check
*Return: 1 or 0
*/
int this_isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
*this_strcmp - this function compare string
*@stri1: String one
*@stri2: String two
*Return: 0 always:
*/
int this_strcmp(char *stri1, char *stri2)
{
	int i, countit1, countit2, tmp = 0;

	countit1 = this_strlen(stri1);
	countit1 = this_strlen(stri2);

	if (stri1 == NULL || stri2 == NULL)
		return (1);
	if (countit1 != countit2)
		return (1);
	for (i = 0; stri1[i]; i++)
	{
		if (stri1[i] != stri2[i])
		{
			tmp = stri1[i] - stri2[i];
			break;
		}
		else
			continue;
	}
	return (tmp);
