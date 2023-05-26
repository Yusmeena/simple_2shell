#include "shell.h"

/**
*this_perror - this function display common error
*@argv: this pointer point to address of command argument
*@stri: char line
*@line: Command line
*/

void this_perror(char **argv, int stri, char **line)
{
	char *error_msg = this_itoa(stri);

	PRINTF(argv[0]);
	PRINTF(": ");
	PRINTF(error_msg);
	PRINTF(": ");
	PRINTF(line[0]);
	PRINTF(": Invalid number: ");
	PRINTF(line[1]);
	PRINTF("\n");
	free(error_msg);
}

/**
*this_error - this function display common error
*@argv: the pointer point to the address of arguments
*@stri: char line
*/

void this_error(char **argv, int stri)
{
	char *error_msg = this_itoa(stri);

	PRINTF(argv[0]);
	PRINTF(": ");
	PRINTF(": Unable to open ");
	PRINTF(argv[1]);
	PRINTF("\n");
	free(error_msg);
}
