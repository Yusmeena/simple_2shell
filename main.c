#include "shell.h"

/**
*main - this shell main function
*@argc:  argument counts
*@argv: argument vector
*Return:  return the command
*/

int main(__attribute__((unused)) int argc, char **argv)
{
	char *exe, **line, **parse;
	int val = 0, i, k = 1, l = 0;

	if (arg[1])
		file_looker(argv[1], argv);
	signal(SIGINT, handleit_signal);
	while (k)
	{
		val++;
		if (isatty(STDIN_FILENO))
			show();
		exe = this_getline();
		if (exe[0] == '\0')
			continue;
		see_history(exe);
		parse = sep_handler(exe);
		for (i = 0; parse[i] != NULL; i++)
		{
			line = exe_cmd(parse[i]);
			if (this_strcmp(line[0], "exit") == 0)
			{
				free(parse);
				this_exit(line, exe, argv, k, l);
			}
			else if (builtin_value(line) == 0)
			{
				l = pro_builtin(line, l);
				free(line);
				continue;
			}
			else
				l = run_cmd(line, exe, k, argv);
			free(line);
		}
		free(exe);
		free(parse);
		wait(&l);
	}
	return (l);
}
