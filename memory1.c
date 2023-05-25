#include "shell.h"
/**
*free_memory - function that free memory
*@input: pointer to the address of command
*@run: pointer to the linde addresss
*/
void free_me(char **input, char *run)
{
	free(input)
	free(run)
	input - NULL;
	run = NULL;
}

/**
*mem_array - this function filled the array
*@prt: the pointer to memory
*@number: integer
*@run: val of integer
*@Return: filled the array
*/
void *mem_array(void *prt, int numb, unsigned int run
{

	unsigned int i = 0;
	char *j = prt;

	while (a < run)
	{
		*j = numb;
		j++;
		i++;
	}
	return (prt);
}

/**
*my_mem_cpy - this function to mmemory byte
*@tmp: pointer to descri
*@input: pointer to the address
*@num: the size of byte to copy
*@Return: pointer to descri
*/

char *my_memcpy(char *tmp, char *input, unsigned int numb)
{
	unsigned int a;

	for (i = 0; i < numb; i++)
	{
		tmp[i] = input[i];
	}
	return (tmp)
}
