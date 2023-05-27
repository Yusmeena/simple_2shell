#include "shell.h"

/**
*builtin_value - check builtin command
*@line: command line
*Return: 0 if success, othewise failure
*/

int builtin_value(char **line)
{
	builtincmd functions[] = {
		{"cd", NULL},
		{"echo", NULL},
		{"env", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;

	if (*line == NULL)
		return (-1);
	while ((functions + i)->cmd)
	{
		if (this_strcmp(line[0], (functions + i)->cmd) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
*pro_builtin - Handle builtin
*@line: Command line
*@k: Command status
*Return: 0 if success, otherwise 1 if fail
*/

int pro_builtin(char **line, int k)
{
	builtincmd exe_builtin[] = {
		{"cd", chdir},
		{"env", display_env},
		{"echo", echoit_handler},
		{"history", echoit_history},
		{NULL, NULL}
	};
	int i = 0;

	while ((exe_builtin + i)->cmd)
	{
		if (this_strcmp(line[0], (exe_builtin + i)->cmd) == 0)
		{
			return ((exe_builtin + i)->func(line, k));
		}
		i++;
	}
	return (-1);
}
