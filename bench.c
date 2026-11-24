#include "push_swap.h"



float   disorder(t_stack *a)
{
    t_stack *i;
    t_stack *j;
    float mstk;
    float total;

    mstk = 0;
    total = 0;
    i = a;
    while (i)
    {
        j = i->next;
        while (j)
        {
            if (i->val > j->val)
                mstk++;
            total++;
            j = j->next;
        }
        i = i->next;
    }
    return (mstk / total);
}

// void    ft_bench(t_op op,)
// {
//     static t_count_ops count;

// }