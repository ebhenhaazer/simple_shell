#include "main.h"

/**
* hand_sig - handle sigs
* @signal: signal
*
* Return: 0
*/
void hand_sig(int signal)
{
if (signal == SIGINT)
{
write(STDOUT_FILENO, "\n", 1);
display_prompt();
fflush(stdout);
}
}
