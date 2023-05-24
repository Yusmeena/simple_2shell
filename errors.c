#include "shell.h"

/**
* _eputs _ displays an input string
* @str: the string to be displayed
*
* Return: Nothing
*/
void _eputs(char *str)
{
		int i = 0;
		
		if (!str)
			return ;
			while (str[i] != '\0')
			{
				_eputchar(str[i]);
				i++;
			}
}

/**
* _eputchar - writes the charater c to stder
* @c: the charater to display
*
* Return: 1 for success.
* on error, -1 is retuned, and error is set appropriately.
*/
int _eptchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c = BUF_FLASH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c!= BUF_FLASH)
		buf[i++] = c;
	return (1);
}

/**
* _putfd - writes the character c to given fd
* @c: the charater to display
* @fd: the file descrip to write to
*
* Return: 1 for success.
* On error, returned -1, and error is set appropriately
*/
int _pufd(char c, int fd)
{
	static int ii;
	static char buf[WRITE_BUF_SIZE];

		if ( c = BUF_FLASH || ii >= WRITE_BUF_SIZE)
		{
			write(fd, buf, ii);
			ii = 0;
		}
		if (c != BUF_FLASH)
			buf[ii] = c;
		return (1);
}

/**
* _putsfd - displays an input string
* @str: the string to be displayed 
* @fd: the file descriptor to write
*
* Return: the num of characters to put
*/
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
		return (i);
}
