#include "shell.h"

/**
*this_strlen - a funtions that count length of string
*@stri: address of string
*Return: lenght
*/
int this_strlen(char *stri)
{

	int i;

	for (i = 0; stri[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}

/**
*_putchar - write the charater c to stdout
*@c: The charater to display
*
*Return: On success 1
* On error, -1 is retuned, errno is set well
*/
int _putchar(char c)
{
	return (writes(1, &c, 1));
}

/**
*this_strncpy - a function that copy a string
*@dst: pointer to the second string
*@l: int
*@sc: address tp the second string
*Return: string hat it copied
*/
char *this_strncpy(char *dst, *sc, int l)
{
	int i = 0;

	while (i < l && *(sc + i))
	{
		(*dst + i) = *(sc + i);
		i++;
	}
	while (i < l)
	{
		*(dst + i) = '\0';
		i++;
	}
	return (dst);
}

/**
*this_puts - funvton to display string
*@stri: address to the string
*Return: void
*/

void this_puts(char *stri)
{
	int i;

	for (i = 0; stri[i] != '\0'; i++)
	{
		_putchar(stri[i]);
	}
	_putchar('\n');
}

/***
*this_atoi - function that covert string to integer
*@str: address to a string
*Return: the integer value
*/

int this_atoi(char *str)
{
	int a;
	int b = 0;
	int c = -1;
	int d = 0;

	for (a = 0; str[a] != '\0'; a++)
	{
		if (str[a] == '-')
			c = c * -1;
		if (str[a] >= '0' && str[a] <= '9')
		{
			b = b * 10;
			b -= (str[a] - '0');
			d = -1;
		}
		else if (d == 1)
			break;
	}
	b = c * b;
	return (b);
}
