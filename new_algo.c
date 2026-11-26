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
int ft_part_a(t_stack **a, t_stack **b, int size)
{
    int pivot;
    int pushed;
    int rotate;
    int i;

    pushed = 0;
    rotate = 0;
    i = size;
    pivot = ft_pivot(*a, size);
    while (i-- > 0)
    {
        if ((*a)->val < pivot)
        {
            pb(a, b);
            ft_printf("pb\n");
            pushed++;
        }
        else
        {
            ra(a);
            ft_printf("ra\n");
            rotate++;
        }
    }
    if (stack_len(*a) != size - pushed)
    {
        while (rotate-- > 0)
        {
            rra(a);
            ft_printf("rra\n");
        }
    }
    return (pushed);
}

int ft_part_b(t_stack **a, t_stack **b, int size)
{
    int pivot;
    int pushed;
    int rotate;
    int i;

    pushed = 0;
    rotate = 0;
    i = size;
    pivot = ft_pivot(*b, size);
    while (i-- > 0)
    {
        if ((*b)->val > pivot)
        {
            pa(a, b);
            ft_printf("pa\n");
            pushed++;
        }
        else
        {
            rb(b);
            ft_printf("rb\n");
            rotate++;
        }
    }
    if (stack_len(*b) != size - pushed)
    {
        while (rotate-- > 0)
        {
            rrb(b);
            ft_printf("rrb\n");
        }
    }
    return (pushed);
}

void    quick_sort_a(t_stack **a, t_stack **b, int size)
{
    int pushed;

    if (size == 1 || size == 0)
        return ;
    if (size == 2)
    {
        if ((*a)->val > (*a)->next->val)
        {
            sa(*a);
            ft_printf("sa\n");
        }
        return ;
    }
    pushed = ft_part_a(a, b, size);
    if (!is_sorted(*a))
        quick_sort_a(a, b, size - pushed);
    if (!is_sorted(*b));
        quick_sort_b(a, b, pushed);
}

void    quick_sort_b(t_stack **a, t_stack **b, int size)
{
    int pushed;

    if (size == 0)
        return ;
    if (size == 1)
    {
        pa(a, b);
        ft_printf("pa\n");
        return ;
    }
    if (size == 2)
    {
        if ((*b)->val < (*b)->next->val)
        {
            sb(*b);
            ft_printf("sb\n");
        }
        pa(a, b);
        pa(a, b);
        ft_printf("pa\npa\n");
        return ;
    }
    pushed = ft_part_b(a, b, size);
    if (!is_sorted(*a))
        quick_sort_a(a, b, pushed);
    if (!is_sorted(*b))
        quick_sort_b(a, b, size - pushed);
}
