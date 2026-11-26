#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static int ft_mode(char *str1, char *str2, int *i)
{
    int bench;

    bench = 0;
    *i += 1;
    if (!ft_strncmp("--bench", str1, 7) && !str1[7])
    {
        bench = 4;
        *i += 1;
        if (ft_atoi(str2) != LONG_MAX)
            return (bench + 4);
    }
    else
        str2 = str1;
    if (!ft_strncmp("--simple", str2, 8) && !str2[8])
        return (1 + bench);  
    // if (!ft_strncmp("--medium", str2, 8) && !str2[8])
    //     return (2 + bench);
    if (!ft_strncmp("--complex", str2, 9) && !str2[9])
         return (3 + bench);
    // if (!ft_strncmp("--adaptive", str2, 10) && !str2[10])
    //     return (4 + bench);
    else
    {
        *i -= 1;
        return (0);
    }
}

static void    execut_mode(t_stack **a, t_stack **b, int mode)
{
    if (mode == 1 || mode == 0)
        n2sort(a, b);
    // else if (mode == 2)
    //     nsqrtnsort(a, b);
    else if (mode == 3)
        quick_sort_a(a, b, stack_len(*a));
    // else if (mode == 4)
    //     adptsort(a, b);
    else
    {
    //     ft_bench();
        if (mode == 5)
            n2sort(a, b);
    //     else if (mode == 6)
    //         nsqrtnsort(a, b);
        else if (mode == 7)
            quick_sort_a(a, b, stack_len(*a));
    //     else if (mode == 8)
    //         adptsort(a, b);
    }
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
        if (nbr == LONG_MAX)
        {
            free_stack(a);
            ft_printf("1Error\n");
            return (0);
        }
        if (nbr < INT_MIN || nbr > INT_MAX)
        {
            free_stack(a);
            ft_printf("2Error\n");
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
    int mode;

    if (ac <= 1)
        return (0);
    i = 0;
    mode = ft_mode(av[1], av[2], &i);
    if (!creat_stack(&a, av, i, ac - 1))
        return (0);
    if (has_dubs(a))
        return (free_stack(&a),  ft_printf("3Error\n"), 0);
    return (execut_mode(&a, &b, mode),ft_print_list(a), 0);
}
