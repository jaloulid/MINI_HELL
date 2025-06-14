#include "minishell.h"

// int main(int ac, char **av, char **env)
// {
//     char *input;

//     t_node *envv = env_init(env);
//     while (1)
//     {
//         input = readline("myshell> ");
//         if (!input)
//             break;
//         if (input)
//         {
//             // function excute command
//         }
//         free(input); // must free the string returned
//     }

// }

int main(int ac, char **av, char **env)
{
    // t_node *envv = env_init(env);
    // int i = ft_export(av, &envv);
    // ft_export(av, &envv);
    // ft_unset(&envv, "SHLVL");
    // while(envv)
    // {
    //    printf("%s=%s\n", envv->key, envv->value);
    //     envv = envv->next;
    // }
    (void)ac;
    (void)env;
    return (ft_echo(av));
    // while(1)
    // {
    //     int i;
    //     int k;
    //     k = read(0,&i,4);
    //     if(i < 10)
    //     {
    //         ft_putstr_fd("pls enter a number superieur to 10",1);
    //     }
    //     else
    //         exit(0);
    // }
}
