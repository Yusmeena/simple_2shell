#include "shell.h"

/**
*this_strdup - this function duplicate or copy a string
*@sf: pointer to the address of the string
*Return: string copied or duplicated
*/

char *this_strdup(char *sf)
{
	size_t countit;
	size_t i;
	char *sf2;

	countit = this_strlen(sf);
	sf2 = malloc(sizeof(char) * (countit + 1));

	if (sf2 == NULL)
		return (NULL);
	for (i = 0; i <= countit; i++)
	{
		sf2[i] = sf[i];
	}
	return (sf2);
}
/**
*this_strncmp - this function compare two strings
*@stri1: pointer to the address of string one
*@stri2: pointer to the addresss of string two
*@numb: number of character compared
*Return: 0 if success
*/

int this_strncmp(const char *stri1, const char *stri2, size_t numb)
{
	size_t i;

	if (!stri1)
		return (-1);
	for (i = 0; i < numb && stri2[i]; i++)
	{
		if (stri1[i] != stri2[i])
			return (1);
	}
	return (0);
}

/**
*this_strchr - this function check if there is character in a string
*@stri: ointer to the addree of the string to check
*@c:  this denotes character in the string
*Return: pointer to the string
*/
char *this_strchr(char *stri, char c)
{
	for (; *stri != '\0'; stri++)
	{
		if (*stri == c)
		{
			return (stri);
		}
	}
	return (NULL);
}

/**
*see_echo - this is function for built-in echo function
*@line: Pointer to address command
*Return: 0 if success, otherwise -1
*/
int see_echo(char **line)
{
	pid_t pid;
	int look;

	pid = fork();
	if (pid == 0)
	{
	if (execve("/bin/echo", line, environ) == -1)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &look, WUNTRACED);
		} while (!WIFEXITED(look) && !WIFSIGNALED(look));
	}
	return (1);
}
