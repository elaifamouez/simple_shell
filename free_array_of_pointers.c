#include "shell.h"
/**
 * free_array_of_pointers - frees each pointer of an array of pointers and the
 * array too
 * @array: array of pointers
 * Return: nothing
 */
void free_array_of_pointers(char **array)
{
int i;

if (array != NULL)
{
for (i = 0; array[i]; i++)
free(array[i]);
free(array);
array = NULL;
}
}
