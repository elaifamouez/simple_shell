#include "shell.h"
/**
 * shell_loop - its a infinite loop that shows the prompt
 * @prompt: prompt to be printed
 * @data: its a infinite loop that shows the prompt
 */
void shell_loop(char *prompt, data_of_program *data)
{
int error_code = 0, string_len = 0;

while (++(data->exec_counter))
{
_print(prompt);
error_code = string_len = _getline(data);
if (error_code == EOF)
{
free_all_data(data);
exit(errno);
}
if (string_len >= 1)
{
expand_alias(data);
expand_variables(data);
tokenize(data);
if (data->tokens[0])
{
error_code = run_cmd(data);
if (error_code != 0)
_print_error(error_code, data);
}
free_recurrent_data(data);
}
}
}
