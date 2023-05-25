#include "shell.h"

/**
*dis_err - function ro display error message
*@line: pointer te commaand adrress
*@run: iterate the shell
*@argv: Argument of shell
*/
void dis_error(char *line, int run, char **argv)
{
	char *error_msg;

	PRINTF(argv[0]);
	PRINTF(": ");
	error_msg = my_itoa(run);
	PRINTF(error_msg);
	free(error_msg);
	PRINTF(": ");
	PRINTF(line);
	PRINTF(": it is not found\n");
}
