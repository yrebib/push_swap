#include "push_swap.h"

//// O(n ^ 2)

int stack_len(t_stack *a)
{
    int i;

    i = 0;
    while (a)
    {
        i++;
        a = a->next;
    }
    return (i);
}

int max_pos(t_stack *a)
{
    t_stack *tmp;

    int i;
    int val;
    int pos;

    if (!a || !a->next)
        return (-1);
    tmp = a;
    val = a->val;
    i = 0;
    while (tmp)
    {
        if (val > tmp->val)
        {
            val = tmp->val;
            pos = i;
        }
        i++;
        tmp = tmp->next;
    }
    return (pos + 1);
}

void    n2sort(t_stack **a, t_stack **b)
{
    int i;
    int stk_len;
    int end;

    if (is_sorted(*a))
        return ;
    end = max_pos(*a);
    stk_len = stack_len(*a);
    while (end != -1)
    {
        if (end > stk_len / 2)
        {
            i = stk_len - end + 1;
            while (i-- > 0)
            {
                rra(a);
                ft_printf("rra\n");
            }
        }
        else
        {
            i = end - 1;
            while (i-- > 0)
            {
                ra(a);
                ft_printf("ra\n");
            }
        }
        pb(b, a);
        ft_printf("pb\n");
        end = max_pos(*a);
        stk_len--;
    }
    while (pa(a, b)) 
        ft_printf("pa\n");
}
//////

//// O(n * log(n))

// void    nlognsort(t_stack **a, t_stack **b)
// {
//     return ;
// }

////

//// O(n * sqrt(n))

int ft_pivot(t_stack *a)
{
    int max;
    int min;

    max = a->val;
    min = max;
    while (a)
    {
        if (min > a->val)
            min = a->val;
        if (max < a->val)
            max = a->val;
        a = a->next;
    }
    return ((min + max) / 2);
}

void    nsqrtnsort(t_stack **a, t_stack **b)
{
    int pivot;
    int len;

    len = stack_len(*a);
    if (len == 2)
    {
        if ((*a)->val > (*a)->next->val)
        {
            sa(*a);
            ft_printf("sa\n");
        }
        return ;
    }
    pivot = ft_pivot(*a);
    while (len-- > 0)
    {
        if ((*a)->val < pivot)
        {
            pb(b, a);
            ft_printf("pb\n");
        }
        else    
        {
            ra(a);
            ft_printf("ra\n");
        }
    }
    nsqrtnsort(a, b);
    nsqrtnsort(b, a);
}

///

//// adapt

// void    adptsort(t_stack **a, t_stack **b)

///