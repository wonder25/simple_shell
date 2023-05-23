#ifndef MAIN_H
#define MAIN_H

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64       /* max number of whitespace/" " */

#define MAX_ARGS 64
#define MAX_PATH 1024
#define DELIMITERS " \t\r\n\a"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;
/**
 * struct linkedList - path linked list
 * @str: path directories
 * @next: pointer to the next node
 */
typedef struct linkedList
{
	char *str;
	struct linkedList *next;
} LL;

/* functions prototypes */

ssize_t my_getline(char **lineptr, size_t *n, int fd);
void prompt(void);
void handle_input(char *input);
int tokenize(char *input, char **tokens, int max_tokens);
void execute(char **tokens);
int my_strcmp(const char *str1, const char *str2);
void handle_semicolon(char *input);
int file_input(int argc, char **argv);
char *command_checker(char **tokens);
char *myStrcpy(char *dest, const char *src);
char *myStrcat(char *dest, const char *src);
int myStrncmp(const char *s1, const char *s2, size_t n);
int execute_command(char **args, char *path[]);
char *find_executable(char *command, LL *path_list);
LL *path_list();
void execute_builtins(char **tokens, char **env);
char *read_input(void);
void print_string(char *str);
int get_stringlength(const char *str);
void write_string(char *str);
int my_strcmp(const char *str1, const char *str2);
char *get_env(const char *name);
char *my_strdup(const char *str);
void free_list(LL *head);
void print_list(LL *head);
char *concatenateStrings(char *str1, char *str2);
int myStrncmp(const char *s1, const char *s2, size_t n);


int custom_setenv(const char *name, const char *value, int overwrite);
int custom_unsetenv(const char *name);




#endif
