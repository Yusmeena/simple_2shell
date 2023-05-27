#include "shell.h"

/**
*this_getline - this function reads what the user enter
*Return: the insert by user on a buffer
*/

char *this_getline()
{
	int tmp, tmp1, buffsiz = BUF_SIZE;
	char c = 0, *buffer, *buff;

	buffer = malloc(buffsiz);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	for (tmp = 0; c != EOF && c != '\n'; tmp++)
	{
		fflush(stdin);
		tmp1 = read(STDIN_FILENO, &c, 1);
		if (tmp1 == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[tmp] = c;
		if (buffer[0] == '\n')
			return (this_ent(buffer));
		if (tmp >= buffsiz)
		{
			buffer = realloc(buffer, (buffsiz + 2));
			if (!buffer)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	buffer[tmp] = '\0';
	buff = this_space(buffer);
	free(buffer);
	this_hash(buff);
	return (buff);
}

/**
*create_env - this function creates environment variables
*@line: Array of string to store
*/
void create_env(char **line)
{
	int i;

	for (i = 0; environ[i]; i++)
		line[i] = this_strdup(environ[i]);
	line[i] = NULL;
}
/**
*env_mem_free - this free environ memory array
*@insert: Array of environ variables
*/
void env_mem_free(char **insert)
{
	int i;

	for (i = 0; insert[i]; i++)
	{
		free(insert[i]);
	}
}
