#include "shell.h"
/**
*free_memory - function that free memory
*@insert: pointer to the address of command
*@exe: pointer to the line addresss
*/
void free_memory(char **insert, char *exe)
{
	free(insert);
	free(exe)
	insert = NULL;
	exe = NULL;
}

/**
*mem_array - this function filled the array
*@prt: the pointer to memory
*@numb: integer
*@exe: val of integer
*Return: filled the array
*/
void *mem_array(void *prt, int numb, unsigned int exe)
{

	unsigned int i = 0;
	char *j = prt;

	while (a < exe)
	{
		*j = numb;
		j++;
		i++;
	}
	return (prt);
}

/**
*this_memcpy - this function to mmemory byte
*@tmp: pointer to address
*@insert: pointer to the address
*@numb: the size of byte to copy
*Return: pointer to address
*/

char *this_memcpy(char *tmp, char *insert, unsigned int numb)
{
	unsigned int i;

	for (i = 0; i < numb; i++)
	{
		tmp[i] = insert[i];
	}
	return (tmp)
}
