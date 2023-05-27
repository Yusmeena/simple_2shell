#include "shell.h"

/**
*exe_cmd - Function to parse stdin command
*@line: string parse to command
*Return: command
*/

char **exe_cmd(char *line)
{
	char **inserts, *insert;
	int i, buf = BUF_SIZE;

	if (line[0] == ' ' && line[this_strlen(line)] == ' ')
		exit(0);
	if (!line)
		return (NULL);
	inserts = malloc(sizeof(char *) * buf);
	if (inserts == NULL)
	{
		free(inserts);
		perror("hsh");
		return (NULL);
	}
	insert = this_strtok(line, "\n\t\r\a ");
	for (i = 0; insert; i++)
	{
		inserts[i] = insert;
		insert = this_strtok(NULL, "\n\t\r\a ");
	}
	inserts[i] = NULL;
	return (inserts);
}
