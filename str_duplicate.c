#include "shell.h"
/**
 * str_duplicate - duplicates an string
 * @string: String to be copied
 * Return: pointer to the array
 */
char *str_duplicate(char *string)
{
char *result;
int length, i;

if (string == NULL)
return (NULL);
length = str_length(string) + 1;
result = malloc(sizeof(char) * length);
if (result == NULL)
{
errno = ENOMEM;
perror("Error");
return (NULL);
}
for (i = 0; i < length ; i++)
{
result[i] = string[i];
}
return (result);
}
