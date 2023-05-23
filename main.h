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
#include <fcntl.h>
#include <errno.h>

/* functions prototypes */

void prompt();
void handle_input(char *input);
int tokenize(char *input, char **tokens, int max_tokens);
void execute(char **tokens);
int my_strcmp(const char *str1, const char *str2);
void handle_semicolon(char *input);
int file_input(int argc, char **argv);



#endif
