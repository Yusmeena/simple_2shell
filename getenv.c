#include "shell.h"

/**
*this_getenv - function the get environment of a shell
*@env: pointer
*Return: sum environ NULL
*/

char *this_getenv(char *env)
{

	size_t env_leng, sum_leng;
	char *sum;
	int i, j, k;

	env_leng = this_strlen(env);
	for (i = 0; environ[i]; i++)
	{
		if (this_strncmp(env, environ[i], env_leng) == 0)
		{
			sum_leng = this_strlen(environ[i]) - env_leng;
			sum = malloc(sizeof(char) * sum_leng);
			if (sum == NULL)
			{
				free(sum);
				perror("Can't allocate");
				return (NULL);
			}
			j = 0;
			for (k = env_leng + 1; environ[i][k]; k++, j++)
			{
				sum[j] = environ[i][k];
			}
			sum[j] = '\0';
			return (sum);
		}
	}
	return (NULL);
}
/**
*doit_cmd - this function create a cmd
*@insert: pointer to cmd address
*@sum: pointer to folder or dirctory
*Return: path or NULL if failure
*/
char *doit_cmd(char *insert, char *sum)
{
	char *tok;
	size_t exe;

	exe = this_strlen(sum) +  this_strlen(insert) + 2;
	tok = malloc(sizeof(char) * exe);
	if (!tok)
	{
		free(tok);
		return (NULL);
	}
	memset(tok, 0, exe);

	tok = this_strcat(tok, sum);
	tok = this_strcat(tok, "/");
	tok = this_strcat(tok, insert);

	return (tok);
}
