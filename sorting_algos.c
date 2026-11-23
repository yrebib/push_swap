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

    if (!a)
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

void    n2sort(t_stack **a, t_stack **b) // 
{
    int i;
    int stk_len;
    int end;

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
                printf("rra\n");
            }
        }
        else
        {
            i = end - 1;
            while (i-- > 0)
            {
                ra(a);
                printf("ra\n");
            }
        }
        pb(b, a);
        printf("pb\n");
        end = max_pos(*a);
        stk_len--;
    }
    while (pa(a, b)) 
        printf("pa\n");
}
///////

void    n22sort(t_stack **a, t_stack **b) // trush
{
    while (pb(b, a))
    {
        printf("pb\n");
        if ((*b)->next && (*b)->val < (*b)->next->val)
        {
            sb(*b);
            printf("sb\n");
        }
    }
    while (pa(a, b))
    {
        printf("pa\n");
        if ((*a)->next && (*a)->val > (*a)->next->val)
        {
            sa(*a);
            printf("sa\n");
        }
    }
    if (!is_sorted(*a))
        n22sort(a, b);
}

//////



//// O(n * sqrt(n))

void    nsqrtnsort(t_stack **a, t_stack **b)
{
    
}