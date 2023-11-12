#include "shell.h"
/**
* is_shell_builtin - function to handle builtin
* @info: argument 1
* @status: argument 2
* Return: 0 if success, -1 failed
*/
int is_shell_builtin(shellData *info, int status)
{
if (my_strcmp(info->args[0], "exit") == 0)
{
exit(status);
}
else if (my_strcmp(info->args[0], "env") == 0)
{
env();
return (0);
}
else if (my_strcmp(info->args[0], "cd") == 0)
{
cd_builtin_command(info);
return (0);
}
return (-1);
}
/**
* env - function to display environment variable
*
* Return: converted integer
*/
void env(void)
{
int length;
size_t i;

for (i = 0; environ[i] != NULL; i++)
{
length = my_strlen(environ[i]);
write(1, environ[i], length);
write(STDOUT_FILENO, "\n", 1);
}
}
/**
* cd_builtin_command - function to convert string to a integer
* @info: argument 1
* Return: 0 if success, -1 if failed
*/
int cd_builtin_command(shellData *info)
{
int val = -1;
char cwd[PATH_MAX];

if (info->args[1] == NULL)
val = chdir(getenv("HOME"));
else if (my_strcmp(info->args[1], "-") == 0)
{
val = chdir(getenv("OLDPWD"));
}
else
val = chdir(info->args[1]);

if (val == -1)
{
perror("hsh");
return (-1);
}
else if (val != -1)
{
getcwd(cwd, sizeof(cwd));
setenv("OLDPWD", getenv("PWD"), 1);
setenv("PWD", cwd, 1);
}
return (0);
}

/**
* _callenv - custom getenv function
* @var: argument 1
* Return: env if success, NULL if failed
*/
char *_callenv(char *var)
{
char *tmp, *key, *val, *env;
int i;
for (i = 0; environ[i]; i++)
{
tmp = my_strdup(environ[i]);
key = strtok(tmp, "=");
if (my_strcmp(key, var) ==  0)
{
val = strtok(NULL, "\n");
env = my_strdup(val);
free(tmp);
return (env);
}
free(tmp), tmp = NULL;
}
return (NULL);
}
