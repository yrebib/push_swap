
#include "push_swap.h"

////// all this function return 0 if notjing i done
////////////////////////////// -1 if an error
//////////////////////////////  1 if all is good

void	free_stack(t_stack **a)
{
	t_stack *tmp;

	while (*a)
	{
		tmp  = *a;
		*a = (*a)->next;
		free(tmp);
	}
	*a = NULL;
}

int	push(t_stack **a, int val)
{
	t_stack	*new;

	// if (!a)
	// 	return (0);
	new = malloc(sizeof(t_stack));
	if (!new)
		return (-1);
	*new = (t_stack){val, NULL};
	if (!*a)
		*a = new;
	else
	{
		new->next = *a;
		*a = new;
	}
	return (1);
}

int 	tail(t_stack **a, int val)
{
	t_stack	*new;
	t_stack	*tmp;

	// if (!a)
	// 	return (0);
	new = malloc(sizeof(t_stack));
	if (!new)
		return (-1);
	*new = (t_stack){val, NULL};
	if (!*a)
		*a = new;
	else
	{
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

int	pop(t_stack **b, int flag)
{
	t_stack *tmp;
	t_stack *prev;

	// if (!b || !*b)
	// 	return (0);
	if (flag == 0 || !(*b)->next)
	{
		tmp = *b;
		(*b) = (*b)->next;
		free(tmp);
	}
	else if (flag == 1)
	{
		tmp = *b;
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;	
		}
		prev->next = NULL;
		free(tmp);
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

int	is_sorted(t_stack *a)
{
	if (!a || !a->next)
		return 1;
	while (a->next)
	{
		if (a->val > a->next->val)
			return (0);
		a = a->next;
	}
	return (1);
}

//////////////////////////////////////////////////////////////////////

int	sa(t_stack *a)
{
	int	tmp;

	if (!a || !a->next)
		return (0);
	tmp = a->val;
	a->val = (a->next)->val;
	(a->next)->val = tmp;
	return (1);	
}

int	sb(t_stack *b)
{
	return(sa(b));
}

int	ss(t_stack *a, t_stack *b)
{
	return (sa(a) * sb(b));
}

int		pa(t_stack **a, t_stack **b)
{
	if (!b || !*b)
		return (0);
	if (push(a, (*b)->val) == -1)
		return (free_stack(a), free_stack(b), -1);
	pop(b, 0);
	return (1);
}

int		pb(t_stack **a, t_stack **b)
{
	return (pa(b, a));
}

int	ra(t_stack **a)
{
	if (!a || !*a)
		return (0);
	if (tail(a, (*a)->val) == -1)
		return (free_stack(a), -1);
	pop(a, 0);
	return (1);
}

int	rb(t_stack **b)
{
	return (ra(b));
}

int	rr(t_stack **a, t_stack **b)
{
	return (ra(a) * rb(b));
}

int	rra(t_stack **a)
{
	t_stack	*tmp;
	int	val;

	if (!a || !*a)
		return (0);
	if (!(*a)->next)
		return (1);
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	val = tmp->val;
	pop(a, 1);
	if (push(a, val) == -1)
		return (free_stack(a), -1);
	return (1);
}

int	rrb(t_stack **b)
{
	return (rra(b));
}

int rrr(t_stack **a, t_stack **b)
{
	return (rra(a) * rrb(b));
}