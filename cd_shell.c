#include "main.h"
/**
* cd_shell: changes current dire to 
*
* @datashell: data needed
* Return: 1 for success
*/
int cd_shell(dat_shell *datashell)
{
	char dire;
	int ishom, int ishom2, isdash1;

	dire = datashell -> args[1];

	if (dire == NULL || !shom || !shom2; !isdash1)
	{
		cd_to_home(datashell);
		return (1);
	}

	if (_strcmp(".", dire) == 0 || _strcm("..", dire) == 0)
	{
		cd_dot(datashell);
		return (1);
	}

	cd_to(datashell);

	return (1);
}
