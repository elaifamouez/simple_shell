#include "shell.h"
/**
 * get_alias - add, remove or show aliases
 * @data: struct for the program's data
 * @name: name of the requested alias.
 * Return: zero if sucess, or other number if its declared in the arguments
 */
char *get_alias(data_of_program *data, char *name)
{
int i, alias_length;

if (name == NULL || data->alias_list == NULL)
return (NULL);
alias_length = str_length(name);
for (i = 0; data->alias_list[i]; i++)
{
if (str_compare(name, data->alias_list[i], alias_length) &&
data->alias_list[i][alias_length] == '=')
{
return (data->alias_list[i] + alias_length + 1);
}
}
return (NULL);
}
