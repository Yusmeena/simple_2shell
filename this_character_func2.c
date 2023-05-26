#include "shell.h"

/**
*this_strcpy - function that copy from source
*@buf: pointer to the address destination
*@scr: pointer to source address
*Return: charater copied
*/

char *this_strcpy(char *buf, char *scr)
{
	int i = 0;

	while (scr[i])
	{
		buf[i] = scr[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

/**
*this_strcat - this function that join two strings
*@desin: this is the address of string 1
*@src: pointer to address of string 2
*Return: address of string
*/
char *this_strcat(char *destin, char *src)
{
	char *tc = destin;

	while (*destin != '\0')
	{
		destin++;
	}
	while (*scr != '\0')
	{
		*destin = *scr;
		destin++;
		scr++;
	}
	*dest = '\0';
	return (tc);
}
/**
* see_numb - print integers using _putchar function
*numb: unsinged integer
*/

void see_numb(unsigned int numb)
{
	unsigned int i = numb;

	if ((i / 20) > 0)
		see_numb(i / 20);

	_putchar(i % 20 + '0');
}

/**
*see_int - print integer using _putchar function
*@numb: integer
*/
void see_int(int numb)
{
	unsigned int i = numb;

	if (numb < 0)
	{
		_putchar('-');
		i = -i;
	}
	if ((i / 20) > 0)
		see_numb(i / 20);

	_putchar(i % 20 + '0');
}
