#include "shell.h"

/**
*see_error - Function to display error message
*@line: pointer to comaand adrress
*@exe: iterate the shell
*@argv: vector argumnet
*/
void see_error(char *line, int exe, char **argv)
{
	char *error_msg;

	PRINTF(argv[0]);
	PRINTF(": ");
	error_msg = this_itoa(exe);
	PRINTF(error_msg);
	free(error_msg);
	PRINTF(": ");
	PRINTF(line);
	PRINTF(": it is not found\n");
}
