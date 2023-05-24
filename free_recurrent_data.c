#include "shell.h"
/**
 * free_recurrent_data - free the fields needed each loop
 * @data: struct of the program's data
 * Return: Nothing
 */
void free_recurrent_data(data_of_program *data)
{
if (data->tokens)
free_array_of_pointers(data->tokens);
if (data->input_line)
free(data->input_line);
if (data->command_name)
free(data->command_name);
data->input_line = NULL;
data->command_name = NULL;
data->tokens = NULL;
}
