#include "shell.h"

/**
*sep_handler - This function handle seperator
*@cmd: command to execute
*Return: all commands
*/
char **sep_handler(char *cmd)
{
	char **inserts;
	char *insert;
	int i;
	int buff = BUF_SIZ;

	if (cmd[0] == ' ' && cmd[this_strlen(cmd)] == ' ')
		exit(0);
	if (!cmd)
		return (NULL);
	inserts = malloc(sizeof(char *) * buff);
	if (inserts == NULL)
	{
		free(inserts);
		perror("hsh");
		return (NULL);
	}
	insert = this_strtok(cmd, ";&");
	for (i = 0; insert; i++)
	{
		inserts[i] = insert;
		insert = this_strtok(NULL, ";&");
	}
	inserts[i] = NULL;
	return (inserts);
}

/**
*see_history - Function to keep users history or event
*@line: Command line
*Return: 1 if success
*/

int see_history(char *line)
{
	int exe = 0;
	char *fname = ".display_history";
	ssize_t rd, wt;

	if (fname == NULL)
		return (-1);
	rd = open(fname, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (rd < 0)
		return (-1);
	if (line != NULL)
	{
		while (line[exe])
			exe++;
		wt = write(rd, line, exe);
		if (wt < 0)
			return (-1);
	}
	return (1);
