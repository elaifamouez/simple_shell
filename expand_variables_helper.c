#include "shell.h"
/**
 * expand_variables_helper - helper function to expand variables
 * @data: a pointer to a struct of the program's data
 * @line: the input line to expand variables in
 */
void expand_variables_helper(data_of_program *data, char *line)
{
int i, j;
char expansion[BUFFER_SIZE] = {'\0'}, *temp;

for (i = 0; line[i]; i++)
if (line[i] == '#')
{
if (i == 0 || line[i - 1] == ' ')
line[i] = '\0';
}
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
}
