#include "shell.h"
/**
 * builtin_env - shows the environment where the shell runs
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_env(data_of_program *data)
{
int i;
char cpname[50] = {'\0'}, *var_copy = NULL;

if (data->tokens[1] == NULL)
print_environ(data);
else
{
for (i = 0; data->tokens[1][i]; i++)
{
if (data->tokens[1][i] == '=')
{
var_copy = str_duplicate(env_get_key(cpname, data));
if (var_copy != NULL)
env_set_key(cpname, data->tokens[1] + i + 1, data);
print_environ(data);
if (env_get_key(cpname, data) == NULL)
{
_print(data->tokens[1]);
_print("\n");
}
else
{
env_set_key(cpname, var_copy, data);
free(var_copy);
}
return (0);
}
cpname[i] = data->tokens[1][i];
}
errno = 2;
perror(data->command_name);
errno = 127;
}
return (0);
}
