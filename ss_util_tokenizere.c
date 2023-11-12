#include "shell.h"
/**
* tokenize_input - function to tokenize input
* @info: argument 1
* Return: void
*/
void tokenize_input(shellData *info)
{
char *token;
const char *delim = " \t\n";
int i = 0;

token = strtok(info->command, delim);
if (!token)
{
exit(0);
}
while (token != NULL)
{
info->args[i++] = token;
token = strtok(NULL, delim);
}
info->args[i] = NULL; /* Null-terminate the args array*/
}

