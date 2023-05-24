#include "shell.h"
/**
 * free_all_data - free all field of the data
 * @data: struct of the program's data
 * Return: Nothing
 */
void free_all_data(data_of_program *data)
{
if (data->file_descriptor != 0)
{
if (close(data->file_descriptor))
perror(data->program_name);
}
free_recurrent_data(data);
free_array_of_pointers(data->env);
free_array_of_pointers(data->alias_list);
}
