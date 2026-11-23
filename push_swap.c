#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>


int  main(int ac, char *av[])
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    int i;

    if (ac <= 1)
        return (0);
    i = 0;
    while (i < ac - 1)
    {
        if (!atoi(av[i + 1]) && ft_strncmp(av[i + 1], "0", 1)
            && ft_strncmp(av[i + 1], "-0", 2) && ft_strncmp(av[i + 1], "+0", 2))
            return (printf("Error\n"), 0);
        tail(&a, atoi(av[i + 1]));
        i++;
    }
    // ft_print_list(a);
    // printf("+++++++++++++++++++++++++\n");
    n2sort(&a, &b);
    // n22sort(&a, &b);
    printf("+++++++++++++++++++++++++\n");
    ft_print_list(a);
    return (0);
}
