#include "shell.h"

/**
* my_strdup -  duplicate string
* @str: argument 1
* Return: ptr
*/

char *my_strdup(const char *str)
{
int len = 0, i;
char *ptr;

if (str == NULL)
{
return (NULL);
}
while (*str != '\0')
{
len++;
str++;
}
str = str - len;
ptr = malloc(sizeof(char) * (len + 1));
if (ptr == NULL)
{
return (NULL);
}
for (i = 0; i <= len; i++)
{
ptr[i] = str[i];
}
return (ptr);
}
/**
* my_strcpy - copies a string
* @dest: the destination
* @src: the source
*
* Return: pointer to destination
*/
char *my_strcpy(char *dest, char *src)
{
int j = 0;

if (dest == src || src == 0)
{
return (dest);
}
while (src[j])
{
dest[j] = src[j];
j++;
}
dest[j] = 0;
return (dest);
}
/**
* my_strlen - gets length of a string
* @str: the string
*
* Return: length of string
*/
int my_strlen(char *str)
{
int len = 0;

while (str[len])
{
len++;
}
return (len);
}
/**
* my_strcmp -  comparison of two strings.
* @s1: string 1
* @s2: string 2
*
* Return: negative, positive or zero
*/
int my_strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
{
return (*s1 - *s2);
}
s1++;
s2++;
}
if (*s1 == *s2)
{
return (0);
}
else if (*s1 < *s2)
{
return (-1);
}
else
{
return (1);
}
}
/**
* my_strcat - concatenates two strings
* @dest: the destination
* @src: the source
*
* Return:  destination pointer
*/
char *my_strcat(char *dest, char *src)
{
char *ret = dest;

while (*dest)
{
dest++;
}
while (*src)
{
*dest++ = *src++;
}
*dest = *src;
return (ret);
}

