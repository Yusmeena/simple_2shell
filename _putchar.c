#include "shell.h"

/**
*_putchar - writes the charater c to stdout
* @w: The charater to display
*
* Return: On success, if error, -1 is returned, 
*@ and errno is set well
*/
int _putchar(char w)
{

	char show;

	show = (write(1, &w, 1));
	return (show);
}
