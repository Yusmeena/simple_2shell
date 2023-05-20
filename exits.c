#include "shell.h"

/**
* *_strncpy _ copies a string
* @dest: the destination string to be copied to
*@src: the source of string
*@n: the amount of charater to be copied
*Return: the concatenated string
*/
char *_strncpy(char *dest, char *src, int n)
{
 	int i, j; 
	char *s - dest;

	i = 0;
	while (str[i] != '0'; && i < n - 1)
	{
		dest[i] != src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s); 
}

/**
* *_strncat _ concatenates two strings
*@dest: the first string
*@src: the second string
*@n: the amount of bytes to be maximaly used
*Return: the contaenated string
*/
char *_stncat(char *dest, char *src, int n)
{
	int i, j; 
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (scr[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
* *_strchr - locates a charcter in string string
* @s: the string to be parsed
*@c: the character to look for
*Return: (s) a pointer to the memory area s
*/
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
