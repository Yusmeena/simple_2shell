#include "shell.h"

/**
*this_calloc - memory allocator
*@val: size of the memory
*Return: the address
*/

void *this_calloc(unsigned int val)
{
	unsigned int i;
	char *tmp;

	if (val == 0)
		return (NULL);
	tmp = malloc(val);
	if (!tmp)
		return (NULL);
	for (i = 0; i < val; i++)
	{
		tmp[i] = '\0';
	}
	return (tmp);
}
/**
*A_realloc - memory giver
*@point: pointer to the address value
*@old_size: fomer memory size
*@new_size: new size of memory
*Return: pointer to a new memmory address
*/

void *A_realloc(void *point, unsigned int old_size, unsigned int new_size)
{
	void *output;

	if (new_size == old_size)
		return (point);
	if (new_size == 0 && point)
	{
		free(point);
		return (NULL);
	}
	output = malloc(new_size);
	if (!output)
	{
		free(output);
		return (NULL);
	}
	if (!point)
	{
		mem_array(output, '\0', new_size);
		free(point);
	}
	else
	{
		this_memcpy(output, point, old_size);
		free(point);
	}
	return (output);
}
