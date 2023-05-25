#include "shell.h"

/**
*this_exit - A function to a shell page
*@line: Command line
*@exe: Command from the user to execute
*@argv:  Vector argument
*@l: countt number of executed
*@c: Exit
*/
void this_exit(char **line, char *exe, char **argv, int l, int c)
{
	int look, i = 0;

	if (line[1] == NULL)
	{
		free(exe);
		free(line);
		exit(c);
	}
	while (line[1][a])
	{
		if (ths_isalpha(line[1][a++]) != 0)
		{
			this_perror(argv, l, line);
			free(exe);
			free(line);
			exit(2);
		}
		else
		{
			look = this_atoi(line[1]);
			if (look == 2)
			{
				this_perror(argv, l, line);
				free(exe);
				free(line);
				exit(look);
			}
			free(exe);
			free(line);
			exit(look);
		}
	}
}
