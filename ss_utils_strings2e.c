#include "shell.h"

/**
* show_err - function to handle error
* @name: argument 1
* @cmd: argument 2
* @idx: argument 3
* Return: void
*/
void show_err(char *name, char *cmd, int idx)
{
char *index, mssg[] = ": not found\n";

index = my_itoa(idx);

write(STDERR_FILENO, name, my_strlen(name));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, index, my_strlen(index));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, cmd, my_strlen(cmd));
write(STDERR_FILENO, mssg, my_strlen(mssg));

free(index);
}
/**
* my_itoa - function to handle builtin
* @n: string input
* Return: buffer
*/
char *my_itoa(int n)
{
char buff[20];
int i = 0;
if (n == 0)
{
buff[i++] = '0';
}
else
{
while (n > 0)
{
buff[i++] = (n % 10) + '0';
n /= 10;
}
}
buff[i] = '\0';
rev_str(buff, i);

return (my_strdup(buff));
}
/**
* rev_str - function to handle builtin
* @str: argument 1
* @len: argument 2
* Return: void
*/
void rev_str(char *str, int len)
{
char tmp;
int start =  0;
int end = len - 1;

while (start < end)
{
tmp = str[start];
str[start] = str[end];
str[end] = tmp;
start++;
end--;
}
}
/**
* _atoi - function to convert string to a integer
* @s: argument 1
* Return: converted integer
*/
int _atoi(char *s)
{
int i = 0, j = 1, k;
unsigned int l = 0;

while (s[i] != '\0')
{
if (s[i] == '-')
{
return (2);
}
k = s[i] - '0';

if (l > 0 && !(k >= 0 && k <= 9))
{
break;
}

if (k >= 0 && k <= 9)
{
l = l * 10 + k;
}

i++;
}
l *= j;
return (l);
}

