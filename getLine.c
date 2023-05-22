#include "shell.h"

/**
* input_buf - buffer chain commands
* @info: parameter struct
* @buf: address of bufffer
* @leng: leng of the var address
*
* Return: byte read
*/
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	ssize_t len_pp = 0;

	if (! * len) /* if nothing remain in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGNINT, signintHandler);
	#if USE_GETLINE
		r = getline(buf, &len_pp, stdin);
	#else
		r = _getline(info, buf, &len_pp)
	#endif
			if (r > 0)
			{
				if ((*buf)[r - 1] == '\n')

