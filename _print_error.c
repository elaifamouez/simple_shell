#include "shell.h"
/**
 * _print_error - writes a array of chars in the standart error
 * @data: a pointer to the program's data'
 * @errorcode: error code to print
 * Return: the number of bytes writed or .
 * On error, -1 is returned, and errno is set appropriately.
 */
int _print_error(int errorcode, data_of_program *data)
{
char n_as_string[10] = {'\0'};

long_to_string((long) data->exec_counter, n_as_string, 10);
if (errorcode == 2 || errorcode == 3)
{
_printe(data->program_name);
_printe(": ");
_printe(n_as_string);
_printe(": ");
_printe(data->tokens[0]);
if (errorcode == 2)
_printe(": Illegal number: ");
else
_printe(": can't cd to ");
_printe(data->tokens[1]);
_printe("\n");
}
else if (errorcode == 127)
{
_printe(data->program_name);
_printe(": ");
_printe(n_as_string);
_printe(": ");
_printe(data->command_name);
_printe(": not found\n");
}
else if (errorcode == 126)
{
_printe(data->program_name);
_printe(": ");
_printe(n_as_string);
_printe(": ");
_printe(data->command_name);
_printe(": Permission denied\n");
}
return (0);
}
