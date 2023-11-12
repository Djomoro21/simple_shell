#include "shell.h"

/**
 * main - Entry point to program
 * @argc: argument count
 * @argv: arguments
 * Return: Returns condition
 */
int main(int argc, char **argv)
{
shellData shellData;
(void)argc;
shellData.idx = 0;
init_shell(&shellData, argv);
return (0);
}

