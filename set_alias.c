#include "shell.h"
/**
 * set_alias - add, or override alias
 * @alias_string: alias to be seted in the form (name='value')
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int set_alias(char *alias_string, data_of_program *data)
{
int i, j;
char buffer[250] = {'0'}, *temp = NULL;

if (alias_string == NULL ||  data->alias_list == NULL)
return (1);
for (i = 0; alias_string[i]; i++)
if (alias_string[i] != '=')
buffer[i] = alias_string[i];
else
{
temp = get_alias(data, alias_string + i + 1);
break;
}
for (j = 0; data->alias_list[j]; j++)
if (str_compare(buffer, data->alias_list[j], i) &&
data->alias_list[j][i] == '=')
{
free(data->alias_list[j]);
break;
}
if (temp)
{
buffer_add(buffer, "=");
buffer_add(buffer, temp);
data->alias_list[j] = str_duplicate(buffer);
}
else
data->alias_list[j] = str_duplicate(alias_string);
return (0);
}
