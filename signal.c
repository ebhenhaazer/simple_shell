#include "main.h"

/**
* sigint_handler - handle sigs
* @signal: signal
*
* Return: 0
*/
void sigint_handler(int signal)
{
if (signal == SIGINT)
{
write(STDOUT_FILENO, "\n", 1);
show_prompt();
fflush(stdout);
}
}
