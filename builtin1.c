#include "shell.h"

/**
*echoit_handler - This builtlin echo handler
*@line: command status
*@k: command status
*Return: Always 1
*/
int echoit_handler(char **line, int k)
{

	unsigned int pid;
	char *look_path;

	pid = getppid();
	if (this_strncmp(line[1], "$?", 2) == 0)
	{
		see_int(k);
		PRINTF("\n");
	}
	else if (this_strncmp(line[1], "$$", 2) == 0)
	{
		see_numb(pid);
		PRINTF("\n");
	}
	else if (this_strncmp(line[1], "$PATH", 5) == 0)
	{
		look_path = this_getenv("PATH");
		PRINTF(look_path);
		PRINTF("\n");
		free(look_path);
	}
	else
		return (see_echo(line));
	return (1);
}

/**
*echoit_history - Funtion that keep history
*@exe: comand line
*@sh: command status
*Return: 0 always
*/
int echoit_history(__attribute__((unused))char **exe,
		__attribute__((unused))int sh)
{
	FILE *v1;
	char *c, *insert = NULL;
	char *fname = ".display_history";
	size_t buf = 0;
	int val = 0;

	v1 = fopen(fname, "r");
	if (!v1)
		return (-1);
	while ((getline(&insert, &buf, v1)) != -1)
	{
		val++;
		c = this_itoa(val);
		PRINTF(c);
		free(c);
		PRINTF(" ");
		PRINTF(insert);
	}
	if (insert != NULL)
		free(insert);
	fclose(v1);
	return (0);
}
