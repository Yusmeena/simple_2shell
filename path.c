#include "shell.h"

/**
*look_path - The function for path for a command
*@command: This pointer to command address
*Return: 0 or 1 failed
*/

int look_path(char **command)
{
	char *look_p;
	char *sum, cmd;
	struct stat buf;


	look_p = this_getenv("PATH");
	sum = this_strtok(look_p, ":");
	while (sum)
	{
		cmd = doit_cmd(*command, sum);
		if (stat(cmd, &buf) == 0)
		{
			*command = this_strdup(cmd);
			free(cmd);
			free(look_p);
			return (0);
		}
		free(look_p);
		sum = this_strtok(NULL, ":");
	}
	free(look_p);
	free(sum);
	return (1);
}
