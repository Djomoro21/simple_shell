#include "shell.h"
/**
*is_interactive -Entry point to program
*
*Return:Returns condition
*/
bool is_interactive(void)
{
return (isatty(0));
}
/**
 * init_shell - Entry point to program
 * @info: argument count
 * @argv: arguments
 * Return: Returns condition
 */
int init_shell(shellData *info, char **argv)
{
char *line = NULL;
int status = 0;
while (1)
{
my_init_data_shell(info);
line = my_get_input(info);
if (line == NULL)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n ", 1);
return (status);
}
info->idx++;
tokenize_input(info);
if (is_shell_builtin(info, status) != -1)
{
continue;
}
status = _execmd(info, argv);
}
return (0);
}

