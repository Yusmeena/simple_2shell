#include "shell.h"

/**
* file_looker - function to read command from file
* @f: file
*@argv: argument or parameter
*/

void file_looker(char *f, char **argv)
{
	FILE *rd;
	char *exe = NULL;
	size_t len = 0;
	int k = 0;

	rd = fopen(f, "r");
	if (!rd)
	{
		this_error(argv, k);
		exit(127);
	}
	while ((getline(&exe, &len, rd)) != -!)
	{
		k++;
		exe_file(exe, k, rd, argv);
	}
	if (exe != NULL)
		free(exe);
	fclose(rd);
	exit(0);


/**
* exe_file - function to handle cmd and exec
*@cmd: pointer to address of command
*@k: Error
*@v1: file descriptor
*@argv: command line argument or parament
*/

void exe_file(char *cmd, int k, FILE *v1, char **argv)
{
	char **exe;
	int look = 0;

	exe = exe_cmd(cmd);
	if (this_strncmp(exe[0], "exit", 4) == 0)
		exit_file(exe, cmd, v1);
	else if (builtin_value(exe) == 0)
	{
		look = pro_builtin(exe, look);
		free(exe);
	}
	else
	{
		look = run_cmd(exe, cmd, k, argv);
		free(exe);
	}
}
/**
*exit_file - exit for file insert
*@insert: insert from a file
*@cmd: Parsed command
*@v1: file descriptor
*/
void exit_file(har **cmd, char *insert, FILE *v1)
{
	int look;
	int i = 0;

	if (cmd[i] == NULL)
	{
		free(insert);
		free(cmd);
		fclose(v1);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (this_isalpha(cmd[1][i++]) < 0)
			perror(" Thia is invalid number");
	}
	look = this_atoi(cmd[1]);
	free(insert);
	free(cmd);
	fclose(v1);
	exit(look);
}
