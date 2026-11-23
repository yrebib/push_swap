#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct	s_stack
{
	int	val;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_ops
{
	char	*op;
	struct s_op	*next;
}				t_ops;

// ruls
void	free_stack(t_stack **a);
int		push(t_stack **a, int val);
int 	tail(t_stack **a, int val);
int		pop(t_stack **b, int flag);
void	ft_print_list(t_stack *a);
int		is_sorted(t_stack *a);


int	sa(t_stack *a);
int	sb(t_stack *b);
int	ss(t_stack *a, t_stack *b);
int	pa(t_stack **a, t_stack **b);
int	pb(t_stack **a, t_stack **b);
int	ra(t_stack **a);
int	rb(t_stack **b);
int	rr(t_stack **a, t_stack **b);
int	rra(t_stack **a);
int	rrb(t_stack **b);
int	rrr(t_stack **a, t_stack **b);
//

void    n2sort(t_stack **a, t_stack **b);
void    n22sort(t_stack **a, t_stack **b);
void    nsqrtnsort(t_stack **a, t_stack **b);

#endif