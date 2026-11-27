#include "push_swap.h"

int op_pop(t_ops **ops)
{
    t_ops *prev;
    t_ops *cur;

    if (!*ops)
        return (0);
    cur = *ops;
    while (cur->next)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    free(cur);
    return (1);
}
int optim_ops(t_ops **ops, char *op)
{
    t_ops   *tmp;

    if (!*ops)
        return (0);
    tmp = *ops;
    while (tmp->next)
        tmp = tmp->next;
    if (!ft_strncmp(tmp->op, "pa", 2) && !ft_strncmp("pb", op, 2))
        return (op_pop(ops));
    if (!ft_strncmp(tmp->op, "pb", 2) && !ft_strncmp("pa", op, 2))
        return (op_pop(ops));
    if (!ft_strncmp(tmp->op, "ra", 2) && !ft_strncmp("rra", op, 3))
        return (op_pop(ops));
    if (!ft_strncmp(tmp->op, "rra", 3) && !ft_strncmp("ra", op, 2))
        return (op_pop(ops));
    if (!ft_strncmp(tmp->op, "rb", 2) && !ft_strncmp("rrb", op, 3))
        return (op_pop(ops));
    if (!ft_strncmp(tmp->op, "rrb", 3) && !ft_strncmp("rb", op, 2))
        return (op_pop(ops));
    if (!ft_strncmp(tmp->op, "sa", 2) && !ft_strncmp("sb", op, 2))
        return (op_pop(ops));
    if (!ft_strncmp(tmp->op, "sb", 2) && !ft_strncmp("sa", op, 2))
        return (op_pop(ops));
    return (0);
}

int  op_tail(t_ops **ops, char *op)
{
    t_ops   *new;
    t_ops   *tmp;

    if (optim_ops(ops, op))
        return (0);
    new = malloc(sizeof(t_ops));
    if (!new)
        return (-1);
    new->op = ft_strdup(op);
    if (!new->op)
        return (-1);
    new->next = NULL;
    if (!*ops)
    {
        *ops = new;
        return (1);
    }
    tmp = *ops;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    return (1);
}

int    op_tracker(t_stack **a, t_stack **b, t_ops **ops, char *op)
{
    int rtrn;

    rtrn = op_tail(ops, op);
    if (rtrn == -1)
    {
        free_stack(a);
        free_stack(b);
        return (-1);
    }
    return (rtrn);
}