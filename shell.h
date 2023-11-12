#ifndef SHELL_H
#define SHELL_H

/*** STANDARD LIBRARIES ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <linux/limits.h>
#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))

extern char **environ;


#define MAX_LINE 80 /* The maximum length command */
#define MAX_ARGS 10 /* The maximum number of arguments per command */
/**
 * struct shellData - Contains infot
 * @args: argumentsd
 * @command: user input as a string
 * @status: status
 * @idx: int de
 */
typedef struct shellData
{
char *args[MAX_ARGS];
char command[MAX_LINE];
int status;
int idx;
} shellData;

void tokenize_input(shellData *info);
char *my_get_input(shellData *info);
int is_shell_builtin(shellData *info, int status);
int my_find_cmd(shellData *info, char **argv);
void my_init_data_shell(shellData *info);
int init_shell(shellData *info, char **argv);
void env(void);
char *my_itoa(int n);
void rev_str(char *str, int len);
int cd_builtin_command(shellData *info);
int _execmd(shellData *info, char **argv);
char *find_cmd_path(char *command);
char *_callenv(char *var);
void show_err(char *name, char *cmd, int idx);


int my_strlen(char *s);
char *my_strdup(const char *str);
char *my_strcat(char *dest, char *src);
int my_strcmp(char *s1, char *s2);
char *my_strcpy(char *dest, char *src);
int _atoi(char *s);

#endif /*SHELL_H*/

