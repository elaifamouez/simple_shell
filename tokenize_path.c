#include "shell.h"
/**
 * tokenize_path - tokenize the path in directories
 * @data: a pointer to the program's data
 * Return: array of path directories
 */
char **tokenize_path(data_of_program *data)
{
int i = 0;
int counter_directories = 2;
char **tokens = NULL;
char *PATH;

PATH = env_get_key("PATH", data);
if ((PATH == NULL) || PATH[0] == '\0')
{
return (NULL);
}
PATH = str_duplicate(PATH);
for (i = 0; PATH[i]; i++)
{
if (PATH[i] == ':')
counter_directories++;
}
tokens = malloc(sizeof(char *) * counter_directories);
i = 0;
tokens[i] = str_duplicate(_strtok(PATH, ":"));
while (tokens[i++])
{
tokens[i] = str_duplicate(_strtok(NULL, ":"));
}
free(PATH);
PATH = NULL;
return (tokens);
}
