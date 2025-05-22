#include "minishell.h"

int main(int ac, char **av, char **env)
{
    char *input;

    t_node *envv = env_init(env);
    while (1)
    {
        input = readline("myshell> ");
        if (!input)
            break;
        // add_history(input); // Optional: adds input to history
        if (input)
        {
            // function excute command
        }
        free(input); // must free the string returned
    }

}