#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static int ft_mode(char *str)
{
    if (!ft_strncmp("--simple", str, 8) && !str[8])
        return (1);  
    // if (!ft_strncmp("--medium", str, 8) && !str[8])
    //     return (2);
    // if (!ft_strncmp("--complex", str, 9) && !str[9])
    //     return (3);
    // if (!ft_strncmp("--adaptive", str, 10) && !str[10])
    //     return (4);
    else
        return (0);
}

static void    execut_mode(t_stack **a, t_stack **b, int mode)
{
    if (mode == 1)
        n2sort(a, b);
    // else if (mode == 2)
    //     nsqrtnsort(a, b);
    // else if (mode == 3)
    //     nlognsort(a, b);
    // else
    //     adptsort(a, b);
    return ;
}

int  main(int ac, char *av[])
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    int i;
    int mode;

    if (ac <= 1)
        return (0);
    i = 0;
    mode = 1;
    if (*av[1] == '-' && *(av[1] + 1) == '-' && ++i)
        mode = ft_mode(av[1]);
    if (mode == 0)
        return (ft_printf("Error\n"), lseekl);
    // ft_printf("mode = %d\n", mode);
    // ft_printf("i = %d\n", i);
    while (i < ac - 1)
    {
        if (!atoi(av[i + 1]) && ft_strncmp(av[i + 1], "0", 1)
            && ft_strncmp(av[i + 1], "-0", 2) && ft_strncmp(av[i + 1], "+0", 2))
            return (ft_printf("Error\n"), 0);
        tail(&a, atoi(av[i + 1]));
        i++;
    }
    execut_mode(&a, &b, mode);
    ft_printf("+++++++++++++++++++++++++\n");
    ft_print_list(a);
    // n22sort(&a, &b);
    // nsqrtnsort(&a, &b);
    // ft_printf("+++++++++++++++++++++++++\n");
    // ft_print_list(a);
    return (0);
}
