#include "shell.h"
/**
 * env_remove_key - remove a key from the environment
 * @key: the key to remove
 * @data: the sructure of the program's data
 * Return: 1 if the key was removed, 0 if the key does not exist;
 */
int env_remove_key(char *key, data_of_program *data)
{
int i, key_length = 0;

if (key == NULL || data->env == NULL)
return (0);
key_length = str_length(key);
for (i = 0; data->env[i]; i++)
{
if (str_compare(key, data->env[i], key_length) &&
data->env[i][key_length] == '=')
{
free(data->env[i]);
i++;
for (; data->env[i]; i++)
{
data->env[i - 1] = data->env[i];
}
data->env[i - 1] = NULL;
return (1);
}
}
return (0);
}
