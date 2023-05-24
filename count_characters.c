#include "shell.h"
/**
 * count_characters - count the coincidences of character in string.
 *
 * @string: pointer to str origen.
 * @character: string with  chars to be counted
 * Return: int of string or 0.
 */
int count_characters(char *string, char *character)
{
int i = 0, counter = 0;

for (; string[i]; i++)
{
if (string[i] == character[0])
counter++;
}
return (counter);
}
