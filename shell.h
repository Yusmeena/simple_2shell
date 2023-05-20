#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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

