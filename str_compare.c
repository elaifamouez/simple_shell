#include "shell.h"
/**
 * str_compare - Compare two strings
 * @string1: String one, or the shorter
 * @string2: String two, or the longer
 * @number: number of characters to be compared, 0 if infinite
 * Return: 1 if the strings are equals,0 if the strings are different
 */
int str_compare(char *string1, char *string2, int number)
{
int iterator;

if (string1 == NULL && string2 == NULL)
return (1);
if (string1 == NULL || string2 == NULL)
return (0);
if (number == 0)
{
if (str_length(string1) != str_length(string2))
return (0);
for (iterator = 0; string1[iterator]; iterator++)
{
if (string1[iterator] != string2[iterator])
return (0);
}
return (1);
}
else
{
for (iterator = 0; iterator < number ; iterator++)
{
if (string1[iterator] != string2[iterator])
return (0);
}
return (1);
}
}
