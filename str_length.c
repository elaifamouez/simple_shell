#include "shell.h"
/**
 * str_length - returns the length of a string.
 * @string: pointer to string.
 * Return: length of string.
 */
int str_length(char *string)
{
int length = 0;

if (string == NULL)
return (0);
while (string[length++] != '\0')
{
}
return (--length);
}
