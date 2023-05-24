#include "shelll.h"

/**
* _myenv - displays the current environment
* @info: Structure entaining parameter. Used to check
* constant function prototype
* Return: Always 0 (zero)
*/
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return(0);
}
/**
* _getenv - collect the value of an enviornment variable
* @info: Structure entaining arameter> used to check constant
* constant function prototype
* @name: environ variable name
*
* Return: the value
*/

char *_getenv(info_t *info, const char *name);
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}
/**
* _mysetenv - create a new environ variable or change an exit one
* @info: structure entainin actual parameters. 
* Used to maintaing constant function prototype
* Return: Always 0 or zero
*/
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs( "The number are incorrect parameters\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->arg[2]))
		return (0);
	return(1);
}
/**
* _myunsetenv - Remove or delete an environ variable
* @info: Structure entaining actual paraments. Used constant
* function prototype
* Return: Always 0 (zero)
*/
int _myunsetenv(info_t *info)
{
	int a;

	if (info->argc == 1)
	{
		_eputs(" The parameters afew. \n");
		return (1);
	}
	for (a = 1; a <= info->argc; a++)
		_unsetenv(info, info->argv[a]);

	return (0);
}
/**
* populate_env_list - populate env linked list
* @info: the structure entails actal parameters. 
* used constant function prototype
* Return: Always 0 (zero)
*/
 
int populate_env_list(info_t, *info)
{
	list_t *node = NULL;
	size_t a;

	for (a = 0; environ[a]; a++)
		add_node_end(&node, environ[a], 0);
	info->env = node;
	return (0);
}
