#include "shell.h"
/**
 * env_set_key - overwrite the value of the environment variable
 * or create it if does not exist.
 * @key: name of the variable to set
 * @value: new value
 * @data: struct of the program's data
 * Return: 1 if the parameters are NULL, 2 if there is an erroror 0 if sucess.
 */
int env_set_key(char *key, char *value, data_of_program *data)
{
int i, key_length = 0, is_new_key = 1;

if (key == NULL || value == NULL || data->env == NULL)
return (1);
key_length = str_length(key);
for (i = 0; data->env[i]; i++)
{
if (str_compare(key, data->env[i], key_length) &&
data->env[i][key_length] == '=')
{
is_new_key = 0;
free(data->env[i]);
break;
}
}
data->env[i] = str_concat(str_duplicate(key), "=");
data->env[i] = str_concat(data->env[i], value);
if (is_new_key)
{
data->env[i + 1] = NULL;
}
return (0);
}
