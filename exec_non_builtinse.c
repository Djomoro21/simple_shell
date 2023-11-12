#include "shell.h"

/**
* _execmd - function to execute non builtin
* @info: argument 1
* @argv: argument 2
* Return: 1 if success
*/
int _execmd(shellData *info, char **argv)
{
char *cmd_path = NULL;
pid_t pid;
int status;
if (info->args)
{
cmd_path = find_cmd_path(info->args[0]);
if (!cmd_path)
{
show_err(argv[0], info->args[0], info->idx);
exit(127);
}
else
{
pid = fork();
if (pid == 0)
{
if (execve(cmd_path, info->args, environ) == -1)
{
perror("Error:");
free(cmd_path), cmd_path = NULL;
}
}
else if (pid < 0)
{
perror("Simpleshell");
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
free(cmd_path), cmd_path = NULL;
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
}
}
return (WEXITSTATUS(status));
}

/**
* find_cmd_path - function to find command path
* @command: argument 1
*
* Return: 1 if success
*/
char *find_cmd_path(char *command)
{
char *my_env_path, *full_cmd, *my_dir;
struct stat st;
int i;

for (i = 0; command[i]; ++i)
{
/* code */
if (command[i] == '/')
{
if (stat(command, &st) == 0)
{
return (my_strdup(command));
}
return (NULL);
}
}
my_env_path = _callenv("PATH");
if (!my_env_path)
return (NULL);
my_dir = strtok(my_env_path, ":");
while (my_dir)
{
full_cmd = malloc(my_strlen(my_dir) + my_strlen(command) + 2);
if (full_cmd)
{
my_strcpy(full_cmd, my_dir);
my_strcat(full_cmd, "/");
my_strcat(full_cmd, command);
if (stat(full_cmd, &st) == 0)
{
free(my_env_path);
return (full_cmd);
}
free(full_cmd), full_cmd = NULL;
my_dir = strtok(NULL, ":");
}
}
free(my_env_path);
return (NULL);
}

/**
* my_find_cmd - function to handle builtin
* @info: string input
* @argv: string input
* Return: 1 if success
*/
int my_find_cmd(shellData *info, char **argv)
{
pid_t pid;
int status;
pid = fork();
if (pid == 0)
{
/* Child process*/
_execmd(info, argv);
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
/* Error forking*/
perror("Simpleshell");
}
else
{
/* Parent process*/
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

return (1);
}

