#include "shell.h"
/**
 * env_get_key - gets the value of an environment variable
 * @key: the environment variable of interest
 * @data: struct of the program's data
 * Return: a pointer to the value of the variable or NULL if it doesn't exist
 */
char *env_get_key(char *key, data_of_program *data)
{
int i, key_length = 0;

if (key == NULL || data->env == NULL)
return (NULL);
key_length = str_length(key);
for (i = 0; data->env[i]; i++)
{
if (str_compare(key, data->env[i], key_length) &&
data->env[i][key_length] == '=')
{
return (data->env[i] + key_length + 1);
}
}
return (NULL);
}
