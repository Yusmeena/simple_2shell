#include "shell.h"

/**
*sh_dir - Function to change a direcory
*@line: command line
*@k: command status
*Return: 0 if success
*/
int sh_dir(char **line, __attribute__((unused))int k)
{
	int count = -1;
	char cwd[PATH_MAX];

	if (line[1] == NULL)
		count = chdir(getenv("HOME"));
	else if (this_strcmp(line[1], "-") == 0)
		count = chdir(getenv("OLDPWD"));
	else
		count = chdir(line[1]);

	if (count == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (count != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
/**
*display_env - Function to display env
*@line: Line command
*@c: command status
*Return: Always 0 (zero)
*/
int display_env(__attribute__((unused)) char **line,
		 __attribute__((unused)) int c)
{
	int value;
	size_t i;

	for (i = 0; environ[i] != NULL; i++)
	{
		value = this_strlen(environ[i]);
		write(1, environ[i], value);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
