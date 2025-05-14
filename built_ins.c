#include "minishell.h"

void    ft_echo(char **argv)
{
    int newline;
    int i;

    newline = 1;
    i = 1;
    if(argv[1] && ft_strncmp(argv[1], "-n", 2) == 0)
    {
        newline = 0;
        i++;
    }
    while (argv[i])
    {
        ft_putstr(argv[i]);
        if (argv[i + 1])
            ft_putchar(' ');
        i++;
    }
    if (newline)
        ft_putchar('\n');
}

void    ft_cd(char **argv)
{

}
