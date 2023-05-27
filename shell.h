#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <linux/limits.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

/* this read/write bufferss */
#define BUF_SIZE 1024
#define DELIMETER "\t\r\n\a"
#define PRINTF(str) (write(STDOUT_FILENO, str, this_strlen(str)))

extern char **environ;

/* This is for error message */
void see_error(char *line, int exe, char **argv);
void this_perror(char **argv, int stri, char **line);
void this_error(char **argv, int stri);

/* builtin */
/*
 *builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
int builtin_value(char **line);
int pro_builtin(char **line, int k);
/*int sh_dir(char **line, __attribute__((unused))int K);*/
int sh_dir(char *line);
/**
*display_env - Funtion to display env
*@line: pointer to command
*@c: line status
*Return: Always 0;
*/
int display_env(__attribute__((unused)) char **line,
			__attribute__((unused)) int c);
int echoit_handler(char **line, int k);
void this_exit(char **line, char *exe, char **argv, int l, int c);

/**
*echoit_history - Funtion to echo his
* @exe: commmand line
* @sh: command, status
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


/* toem_memory.c */
void free_memory(char **insert, char *exe);
void *A_realloc(void *point, unsigned int old_size, unsigned int new_size);
char *this_memcpy(char *tmp, char *insert, unsigned int numb);
void *mem_array(void *prt, int numb, unsigned int exe);
void *this_calloc(unsigned int val);

void env_memory_free(char **insert);
void create_env(char **line);


/* my character functions */
int this_strlen(char *str);
int _putchar(char c);
char *this_strncpy(char *destin, char *sc, int l);
void this_puts(char *strin);
int this_atoi(char *sf);
char *this_strtok(char *st, const char *tk);
unsigned int check_delim(char c, const char *sf);

int this_intlen(int l);
void this_array_rev(char *ar, int b);
char *this_itoa(unsigned int numb);
int this_isalpha(int c);
int this_strcmp(char *stri1, char *stri2);
char *this_strcpy(char *buf, char *scr);
char *this_strcat(char *destin, char *srn);
int this_strncmp(const char *stri1, const char *stri2, size_t num1);
char *this_strdup(char *sf);
char *this_strchr(char *stri, char c);
/**
* struct this_shell - sturcture for builtin cmd
*@exe: to execute line
*@cmd: Pointer to command address
*@func: Pinter to function address
*/

typedef struct this_shell
{

	char *cmd;
	int (*func)(char **exe, int k);
} builtincmd;

/* display */
void see_int(int numb);
void see_numb(unsigned int numb);
int see_echo(char **line);

/* Pathway finder */
char *doit_cmd(char *insert, char *sum);
char *this_getenv(char *env);
int look_path(char **command);
char *this_getline();

/* Command function */
int run_cmd(char  **insert, char *exe, int c, char **argv);
void handleit_signal(int look);
void show(void);
char **sep_handler(char *cmd);
char **exe_cmd(char *line);

char *this_ent(char *stri);
char *this_space(char *sf);
void this_hash(char *tmp);

#endif
