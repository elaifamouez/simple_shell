#include "shell.h"
/**
 * str_concat - concatenates two strings.
 * @string1: String to be concatenated
 * @string2: String to be concatenated
 *
 * Return: pointer to the array
 */
char *str_concat(char *string1, char *string2)
{
char *result;
int length1 = 0, length2 = 0;

if (string1 == NULL)
string1 = "";
length1 = str_length(string1);
if (string2 == NULL)
string2 = "";
length2 = str_length(string2);
result = malloc(sizeof(char) * (length1 + length2 + 1));
if (result == NULL)
{
errno = ENOMEM;
perror("Error");
return (NULL);
}
for (length1 = 0; string1[length1] != '\0'; length1++)
result[length1] = string1[length1];
free(string1);
for (length2 = 0; string2[length2] != '\0'; length2++)
{
result[length1] = string2[length2];
length1++;
}
result[length1] = '\0';
return (result);
}
