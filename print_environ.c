#include "shell.h"
/**
 * print_environ - prints the current environ
 * @data: struct for the program's data
 * Return: nothing
 */
void print_environ(data_of_program *data)
{
int j;

for (j = 0; data->env[j]; j++)
{
_print(data->env[j]);
_print("\n");
}
}
