#ifndef SHARED_H
#define SHARED_H

#include "libft.h"
#include "ft_printf.h"

typedef	struct	s_stack
{
	int32_t	**stack;
	int32_t len;
	int32_t	min;
	int32_t	med;
	int32_t	max;
}				t_stack;


t_stack	*new_stack(size_t len);
int		parse_args(int argc, char *argv[], t_stack *stack);
void    inst_sa(t_list **stack_a, t_list **stack_b, t_bool print);
void    inst_sb(t_list **stack_a, t_list **stack_b, t_bool print);
void    inst_ss(t_list **stack_a, t_list **stack_b, t_bool print);
void    inst_pa(t_list **stack_a, t_list **stack_b, t_bool print);
void    inst_pb(t_list **stack_a, t_list **stack_b, t_bool print);
void    inst_ra(t_list **stack_a, t_list **stack_b, t_bool print);
void    inst_rb(t_list **stack_a, t_list **stack_b, t_bool print);
void    inst_rr(t_list **stack_a, t_list **stack_b, t_bool print);
void    inst_rra(t_list **stack_a, t_list **stack_b, t_bool print);
void    inst_rrb(t_list **stack_a, t_list **stack_b, t_bool print);
void    inst_rrr(t_list **stack_a, t_list **stack_b, t_bool print);
t_bool	is_both_sorted(t_list *stack_a, t_list *stack_b);
t_bool	is_sorted(t_list *stack);
t_bool	is_rsorted(t_list *stack);
void    mem_clean(t_stack *stack_a, t_stack *stack_b);

#endif
