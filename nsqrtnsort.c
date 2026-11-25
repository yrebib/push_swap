#include "push_swap.h"

int stack_is_sort(t_stack *a)
{
    if (!a || !a->next)
        return (1);
    while (a->next)
    {
        if (a->val > a->next->val)
            return (0);
        a = a->next;
    }
    return (1);
}

int ft_pivot(t_stack *a, int len)
{
    int max;
    int min;

    max = a->val;
    min = max;
    while (a && len-- > 0)
    {
        if (min > a->val)
            min = a->val;
        if (max < a->val)
            max = a->val;
        a = a->next;
    }
    return ((min + max) / 2);
}

void    quick_sort_a(t_stack **a, t_stack **b, int size, int pivot)
{
    int pushed = 0;
    int rotate = 0;

    if (!*b && stack_is_sort(*a))
        return ;
    if (size <= 2)
    {
        if (size == 1)
            return ;
        else if ((*a)->val < (*a)->next->val)
        {
            sa(*a);
            printf("sa\n");
        }
        return ;
    }
    while (size-- > 0)
    {
        if ((*a)->val <= pivot)
        {
            pb(a, b);
            printf("pb\n");
            pushed++;
        }
        else
        {
            ra(a);
            printf("ra\n");
            rotate++;
        }
    }
    while (rotate-- > 0 && stack_len(*a) > 2)
    {
        rra(a);
        printf("rra\n");
    }
    quick_sort_a(a, b, size - pushed, ft_pivot(*a, size - pushed));
    quick_sort_b(a, b, pushed, ft_pivot(*b, pushed));
}

void    quick_sort_b(t_stack **a, t_stack **b, int size, int pivot)
{
    int pushed = 0;
    int rotate = 0;

    if (size <= 2)
    {
        if (size == 1)
        {
            pa(a, b);
            printf("pa\n");
            return ;
        }
        else if ((*b)->val <= (*b)->next->val)
        {
            sb(*b);
            printf("sb\n");
            pa(a, b);
            pa(a, b);
            printf("pa\npa\n");
        }
        return ;
    }
    while (size-- > 0)
    {
        if ((*a)->val > pivot)
        {
            pa(a, b);
            printf("pa\n");
            pushed++;
        }
        else
        {
            rb(b);
            printf("rb\n");
            rotate++;
        }
    }
    while (rotate-- > 0 && stack_len(*b) > 2)
    {
        rrb(b);
        printf("rrb\n");
    }
    quick_sort_b(a, b, size - pushed, ft_pivot(*b, size - pushed));
    quick_sort_a(a, b, pushed, ft_pivot(*a, pushed));
}
