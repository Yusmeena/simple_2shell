#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <linux/limits.h>
#include <fcnt1.h>
#include <errno.h>
#include <signal.h>

/* this read/write bufferss */
#define BUF_SIZE 1024
#define DELIMETER "\t\r\n\a"
#define PRINTF(str) (write(STDOUT_FILENO, str, my_strlen(str)))

extern char **environ;

/* This is for error message */
void see_err(char *line, int exe, char **argv);
void this_perror(char **argv, int stri, char **line);
void this_error(char **argv, int stri);

/* builtin */
/*
 *builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
int builtin_value(char **line);
int pro_builtin(char **line, int int k);
int ch_dir(char **line, __attribute__((unused))int K);

/**
*print_env - Funtion to display env
*@line: pointer to mommand
*@k: line status
*Return:Always 0;
*/
int display_env(__attributr__((unused)) char **line,
			__attribute__((unused)) int c);
int echoit_handler(char **line, int k);
void this_exit(char **line, char *exe, char **argv, int l, int c);

/**
*echo_history - Funtion to echo his
* @exe: commmand line
* @ch: command, status
* Return: 0 always
*/
int echoit_history(__attribute__((unused))char **exe,
		__attribute__((unused)) int sh);
/* History */
int see_history(char *line);

/* read my file */
void file_looker(char *v, char **argv);
void exe_file(char *cmd, int k, FILE *v1, char **argv);
void exit_file(char **cmd, char *insert, FILE *v1);

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* check_delim */
unsigned int check_delim(char c, const char *str);

/* toem_realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
void free_me(char **insert, char *exe);
void *A_realloc(void *point, unsigned int old_size, unsigned int new_size);
char *this_memcpy(char *tmp, char *input, unsigned int numb);
void *mem_array(void *prt, int numb, unsigned int exe);
void *this_calloc(unsigned int val);

void env_mem_free(char **insert);
void make_env(char **line);


/* my character functions */
int this_strlen(char *str);
int _put char(char c);
char *this_strncpy(char *dst, char *sc, int int l);
void this_puts(char *stri);
int this_atoi(char *sf);
char *this_strtok(char *st, const char *tk);
unsigned int check_delim(char k, const char *sf);

/**
*struct this_shell - sturcture for builtin cmd
*@cmd: Pointer to command address
*@func: Pinter to function address
*/

typedef struct this_shell
{

	char *cmd;
	int (*fun)(char **exe, int k);
} builtincmd;

/* display */
void see_int(numb);
void see_numb(unsigned int numb);
int see_echo(char **line);

/* Pathway finder */
char *doit_cmd(char *insert, char *total);
char *this_getenv(char *env);
int look_path(char **command);
char *this_getline();

/* Command function */
int run_cmd(char  *insert, char *exe, int c, char **argv);
void handleit_signal(int look);
char show(void);
char **sep_handler(char *cmd);
char **exe_cmd(char *line);

char *this_ent(char *stri);
char *this_space(char *sf);
void this_hash(char *tmp);



#endif
