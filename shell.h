#ifndef SHELL_H
#define SHELL_H

/**### environ var ###**/
extern char **environ;

/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

/** INPUT functions **/
void prompt(void);



/**### MACROS ###**/
#define DISPLAY(c) (write(STDOUT_FILENO, c, _strlen(c)))


/**** Command separator/parser ****/
int is_path_cmd(char **line);
char *_getenv(char *name);
int command_exists(char **tokens, char *line, int count, char **argv);
char *build(char *token, char *value);



/**** String Function ****/
char *_strtok(char *str, const char *tok);
int _strncmp(const char *s1, const char *s2, size_t n);
int _atoi(char *s);
void _puts(char *s);
int _strlen(char *s);
char *_strncpy(char *dest, const char *src, int n);
int _putchar(char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *strcpy(char *dest, const char *src);
char *_strcat(char *dse, const char *src);
char *_strchr(char *s, char c);
char *_itoa(unsigned int n);
char *_strdup(char *str);
void reverse(char *str, int len);

/** error handle and Display **/
void print_error(char *line, int c, char **argv);




#endif

