<<<<<<< HEAD
#ifndef _MAIN_H_
#define _MAIN_H_
=======
#ifndef _SHELL_H_
#define _SHELL_H_
>>>>>>> refs/remotes/origin/main

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
<<<<<<< HEAD
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <erron.h>
#include <fcnt1.h>
#include <signal.h>
#include <limits.h>

/* this is for read/write buffers */
#define BUF_SIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a\\"

/* THis point to array of strings called environment */
extern char **environ;

/**
*struct - data that contain all desired data at execution time
*@argv: an argument vector
*@argc: an argument count
*@input: the command line enter by the user
*@status: the initial stautus of the shell
*@counter: the line counter
*@environ: environment variable
*/
typedef struct data
{
	char **av;
	char *insert
	char **args;
	int status;
	int counter;
	char **_environ;
	int env_changed;
	char *pid;

} data_shell;

/**
*struct_sep_list_s - single linked list
*seperator : ; & |
*next: next node
*description: single linked list that store seperator
*/
typedef struct sepe_list_s
{
char seperator;
struct sepe_list *next;
} sepe_list;

typedef struct lin_list_s
{
	char *lin;
	struct lin_list_s *next;
} lin_list;

/**
*struct r_vari+list _ single linked list
*@leng_var: leng of variable
*@val: variable value
*@leng_val: value's length
*@next: next node
*@desc: Single linked lists to store variable
*/
typedef struct r-vari_lists
{
	int leng_var;
	char *var;
	int leng_val;
	struct r_vari_list *next;
} r_vari;


/**
*struct builtin - contains builtin string and related function
*@type: the builtin command name lke exit, ls, rm, cd
*@func: the function datatype of a pointer
*/
typedef struct builtin
{
	char *type;
	int (*func)(data_shell *datsh);
} builtin_table;

/* toem_lists.c */
sepe_list *add_node(sepe_list **head, char sepe);
void free_sepe_list(sepe_list **head)
lin_list *add_node_end(lin_list **head, char lin);
void free_list(lin_list **head);

/* toem_lists1.c */
r_vari *add_rvar_node(r_vari **head; int var1, char *vari, int val1);
void free_rvari_list(r_vari **head);

/*aux_str functions */
char *_strcat(char *desti, const char *sour);
char *_strcpy(char *deati, char *sour);
int _strcmp(char *st1, char *st2);
char *_strchr(char *str, char c);
int _strsn(char *str, char *acept);

/* aux_mem.c */i
void _memcpy(void *newpt, const void *t, unsigned int siz);
void *_realloc(void *pt, unsigned int old1_siz, unsigned int new1_siz);
char **_reallocd(char **pt, unsigned int old1_siz, unsigned int new1_siz);

/* aux_str1.c */
char *_strdup(const char *str);
int _strleng(const char *str);
int cmp_chars(char str1[], const char *delimt);
char *_strtok(char str1[], const char *delimt);
int _isdigit(const char *str);


/* aux_str2.c */
void rev_string(char *str);

/* check_syntax_error.c */
int repeated_char(char *insert, int a);
int error_sep_op(char *insert, int a);
int first_char(char *insert int *a);
void print_syntax_eror(data_shell *datash, char *insert, int a, int bool);
int check_syntax_error(data_shell *datsh, char *insert);

/* shell_loop */
char *without_comment(char *inn);
void shell_loop(data_shell *datsh);

/* split.c */
char *read_line(int *i_eof);

/* spilt.c */
char *swap_char(char *insert, int bool);
void sum_nodes(sepe_list **head_s, lin_list **head_1, char *insert);
void go_nex(sepe_list **lists, lin_list **list_2, data_shell *dash);
int divide_commands(data_shell *datsh, char *insert);
char **divide_line(char *insert);
=======
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcnt1.h>
#include <errno.h>

/* for read/write bufferss */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLASH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert numbers */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
 * struct liststrr - for singly linked list
 * @num: for the number field
 * @str: a str
 * @next: points to the next node
 * */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo -this contains pseudo-arguments to pass into a function,
 * 	allowing uniform prototype for function pointer struct
 * 	@arg: a string generated from getline containing arguments
 * 	@argv: this is an array of strings generated from arguments
 * 	@path: the path for the current command
 * 	@argc: this is the argument count
 * 	*@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* toem_shloop.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* toem_parser.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* toem_errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* toem_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* toem_exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* toem_tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* toem_realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int bfree(void **);

/* toem_atoi.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* toem_errors1.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* toem_builtin.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* toem_builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/*toem_getline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* toem_getinfo.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* toem_environ.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* toem_getenv.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* toem_history.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* toem_lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* toem_lists1.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* toem_vars.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif
>>>>>>> refs/remotes/origin/main

