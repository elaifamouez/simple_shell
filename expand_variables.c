#include "shell.h"
/**
 * expand_variables - expand variables
 * @data: a pointer to a struct of the program's data
 * Return: nothing, but sets errno.
 */
void expand_variables(data_of_program *data)
{
char line[BUFFER_SIZE] = {0};

if (data->input_line == NULL)
return;
buffer_add(line, data->input_line);
expand_variables_helper(data, line);
if (!str_compare(data->input_line, line, 0))
{
free(data->input_line);
data->input_line = str_duplicate(line);
}
}
