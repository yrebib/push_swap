#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "libft/libft.h"

typedef struct	s_stack
{
	int	val;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_ops
{
	char	*op;
	struct s_ops	*next;
}				t_ops;

// typedef enum	s_op
// {
// 	sa, sb, ss,
// 	pa, pb,
// 	ra, rb, rr,
// 	rra, rrb, rrr,
// 	op_count
// }				t_op;

// typedef struct	s_count_ops
// {
// 	int	count[op_count];
// }				t_count_ops;

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
int		stack_len(t_stack *a);
int		max_pos(t_stack *a);

void    quick_sort_a(t_stack **a, t_stack **b, int size);
void    quick_sort_b(t_stack **a, t_stack **b, int size);
int		ft_part_a(t_stack **a, t_stack **b, int size);
int		ft_part_b(t_stack **a, t_stack **b, int size);
int 	stack_is_sort(t_stack *a);
int 	ft_pivot(t_stack *a, int len);


// void    nlognsort(t_stack **a, t_stack **b);
// void    adptsort(t_stack **a, t_stack **b)

// bench

float   disorder(t_stack *a);


#endif