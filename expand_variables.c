#include "shell.h"
/**
 * expand_variables - expand variables
 * @data: a pointer to a struct of the program's data
 *
 * Return: nothing, but sets errno.
 */
void expand_variables(data_of_program *data)
{
int i, j;
char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

if (data->input_line == NULL)
return;
buffer_add(line, data->input_line);
for (i = 0; line[i]; i++)
if (line[i] == '#')
line[--i] = '\0';
else if (line[i] == '$' && line[i + 1] == '?')
{
line[i] = '\0';
long_to_string(errno, expansion, 10);
buffer_add(line, expansion);
buffer_add(line, data->input_line + i + 2);
}
else if (line[i] == '$' && line[i + 1] == '$')
{
line[i] = '\0';
long_to_string(getpid(), expansion, 10);
buffer_add(line, expansion);
buffer_add(line, data->input_line + i + 2);
}
else if (line[i] == '$' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
continue;
else if (line[i] == '$')
{
for (j = 1; line[i + j] && line[i + j] != ' '; j++)
expansion[j - 1] = line[i + j];
temp = env_get_key(expansion, data);
line[i] = '\0', expansion[0] = '\0';
buffer_add(expansion, line + i + j);
temp ? buffer_add(line, temp) : 1;
buffer_add(line, expansion);
}
if (!str_compare(data->input_line, line, 0))
{
free(data->input_line);
data->input_line = str_duplicate(line);
}
}
