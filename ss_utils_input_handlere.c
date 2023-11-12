#include "shell.h"
/**
* my_init_data_shell - function to tokenize input
* @info: argument 1
* Return: void
*/
void my_init_data_shell(shellData *info)
{
int i;

memset(info->command, 0, MAX_LINE);
for (i = 0; i < MAX_ARGS; i++)
{
info->args[i] = NULL;
}
info->status = 0;
}
/**
* my_get_input- function to tokenize input
* @info: argument 1
* Return: void
*/
char *my_get_input(shellData *info)
{
char *line = NULL;
size_t len = 0;
ssize_t n;
if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, "$ ", 2);
}
n = getline(&line, &len, stdin);
if (n == -1)
{
free(line);
return (NULL);
}
line[n - 1] = '\0';
if (my_strlen(line) > MAX_LINE)
{
free(line);
exit(0);
}
my_strcpy(info->command, line);
free(line);
return (info->command);
}

