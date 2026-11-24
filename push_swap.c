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
    // if (!ft_strncmp("--bench", str, 7) && !str[7])
    //     return (5);
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

static int  has_dubs(t_stack *a)
{
    t_stack *i;
    t_stack *j;

    i = a;
    while (i)
    {
        j = i->next;
        while (j)
        {
            if (i->val == j->val)
                return (1);
            j = j->next;
        }
        i = i->next;
    }
    return (0);
}

static int    creat_stack(t_stack **a, char **av, int start, int end)
{
    int i;
    long nbr;

    i = start;
    while (i < end)
    {
        nbr = ft_atoi(av[i + 1]);
        if (!nbr && ft_strncmp(av[i + 1], "0", 1)
            && ft_strncmp(av[i + 1], "-0", 2) && ft_strncmp(av[i + 1], "+0", 2))
        {
            free_stack(a);
            ft_printf("Error\n");
            return (0);
        }
        if (nbr < INT_MIN || nbr > INT_MAX)
        {
            free_stack(a);
            ft_printf("Error\n");
            return (0);
        }
        tail(a, (int)nbr);
        i++;
    } 
    return (1);
}

int  main(int ac, char *av[])
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    int i;
    int bench;
    int mode;

    if (ac <= 1)
        return (0);
    i = 0;
    mode = 1;
    if (*av[1] == '-' && *(av[1] + 1) == '-' && ++i)
        bench = ft_mode(av[1]);
    if (bench == 5)
    {
        if (*av[1] == '-' && *(av[1] + 1) == '-' && ++i)
            mode = ft_mode(av[2]);
        else
    }
    if (bench == 0 || mode == 0)
        return (ft_printf("Error\n"), 0);
    if (!creat_stack(&a, av, i, ac - 1))
        return (0);
    if (has_dubs(a))
        return (free_stack(&a),  ft_printf("Error\n"), 0);
    return (execut_mode(&a, &b, mode), 0);
}
