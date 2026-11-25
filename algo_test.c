#include "push_swap.h"


int    creat_stack(t_stack **a, char **av, int start, int end)
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

void	ft_print_list(t_stack *a)
{
	int	i = 1;

	while (a)
	{
		printf("node[%d] = %d\n", i++, a->val);
		a = a->next;
	}
}

int main(int ac, char *av[])
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    int i;

    if (!creat_stack(&a, av, i, ac - 1))
        return (0);
    quick_sort_a(&a, &b, ac - 1, ft_pivot(a, ac - 1));
    ft_print_list(a);
    return (0);
}