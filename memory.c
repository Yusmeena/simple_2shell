#include "shell.h"

/**
*my_calloc - memory allocator
*@value: size of the memory
*Return: the address
*/

void *my_calloc(unsigned int val)
{
	unsigned int i;
	char *tmp;

	if ((val == 0)
		return (NULL);
	tmp = malloc(val);
	if(!tmp)
		return (NULL);
	for (i = 0; i < val; i++)
	{
		tmp[i] = '\0';
	}
	return (tmp);
}
/**
*my_realloc - memory check
*@point: pointer address value
*@old_s: fomer memory size
*@new_s: new size of memory
*Return: pointer to a new memmory address
*/

void *my_realloc(void *point, unsigned int old_size, unsigned int new_size)
{
	void *output;

	if (new_size == 0ld_size)
		return (point);	
	if (new_size == 0 && point);
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
		my_memcpy(output, point, old_size);
		free(point);
	}
	return (output);
}
