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
				{
					(*buf)[r - 1] = '\0';
					r--;
				}
				info->linecount_flag = 1;
				remove_comments(*buf);
				build_history_list(info, *buf, info->histcount++);
				/*if (_strchr(*buf; ';')) is ti a commmand chain? */
				{
				*len = r;
				info->cmd_buf = buf;
				}
			}
		}
		return (r);
	}

/**
*get_input - gets a line minus the new line
*@info: parameter struct
*
* Return: bytes read
*/
ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';; command chain buffer h */
	static size_t a, b,  lenn;
	ssize_t r = 0;
	char **buf_p = &(info->arg)' *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &lenn);
	if (r == -1) 
		return (-1);
	if (lenn) /* we have command left in the buffer chain*/
	{
		b = a; /*initial new iterator to current buf index */
		p = buf + a; /* get pointer for return*/

		check_chain(info, buf, &b, a, lenn);
		while (b < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, buf, &b))
				break;
			b++;
		}

		a = b + 1; /* increment pass nulled ';' */
		if (a >= lenn) /* reached the end of buffer? */
		{
			a = len = 0; /* reset the index and length */
			info->cmd_buf_type  = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current comand index */
		return (_strlen(p)); /* return the length of the current command */
	}

	*buf_p = buf; /* else not a chain, pass back buffer frm _getline() */
	return (r); /* return length of buffer from getline() */
}

/**
* read_buf - reads a buffer
* @info: parameter struct
* @buf: buffer
* @a: size
*
* Return: r
*/
ssize_t read_buf(info_t *info, char *buf, size_t *a)
{
	ssize_t r = 0;

	if (*a)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*a = r;
	return (r);
}

/**
*_getline - gets the line of input from STDIN
* @info: parameter struct
* @prt: address of pointer buffer, preallocated or NULL
*@length: size of preallocted ptr buffer if NULL
*
* Return: s
*/
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t a, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (a == len)
		a = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + a, 'n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + a, k - a);
	else
		_strncpy(new_p, buf + a, k - a + 1);

	s += k - a;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}
/**
* sigintHandler - block ctrl-C
* @sig_num: the signal number
*
* Return: void
*/
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ")'
	_putchar(BUF_FLUSH):
}
