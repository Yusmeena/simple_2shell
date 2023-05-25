#include "shell.h"

/**
*exec_cmd - Function to implement command or order
*@insert: Address to command
*@exe: Address to received by cmd
*@c: line implement
*@argv: shell paraments
*Return: 1 if failed otherwise 0 if implement
*/
int exec_cmd(char **insert, char *exe, int c, char **argv)
{
	int look;
	pid_t pid;

	if (!*insert)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("This Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (this_strncmp(*insert, "./", 2) != 0 && this_strncmp(*insert, "/", 1) != 0)
		{
			look_path(insert);
		}
		if (access(insert[0], R_OK) != 0)
		{
			see_err(insert[0], c, argv);
			free_me(insert, exe);
			exit(127);
		}
		if (execve(*insert, insert, environ) == -1)
			return (2);
		else
			return (0);
	}
	wait(&look);
	if (WIFEXITED(look))
	{
		if (WEXITSTATUS(look) == 127)
			return (0);
		else if (WEXITSTATUS(look) == 0)
			return (2);
	}
	return (127);
}
