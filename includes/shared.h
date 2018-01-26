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
int     parse_args(int argc, char *argv[], t_stack *stack_a, t_stack *stack_b);
void    print(char *inst, t_stack *stack_a, t_stack *stack_b, uint64_t opt);

void    inst_sa(t_stack *stack_a, t_stack *stack_b, t_bool print);
void    inst_sb(t_stack *stack_a, t_stack *stack_b, t_bool print);
void    inst_ss(t_stack *stack_a, t_stack *stack_b, t_bool print);
void    inst_pa(t_stack *stack_a, t_stack *stack_b, t_bool print);
void    inst_pb(t_stack *stack_a, t_stack *stack_b, t_bool print);
void    inst_ra(t_stack *stack_a, t_stack *stack_b, t_bool print);
void    inst_raf(t_stack *stack_a, t_stack *stack_b, t_bool print, t_bool plz);
void    inst_rb(t_stack *stack_a, t_stack *stack_b, t_bool print);
void    inst_rbf(t_stack *stack_a, t_stack *stack_b, t_bool print, t_bool plz);
void    inst_rr(t_stack *stack_a, t_stack *stack_b, t_bool print);
void    inst_rra(t_stack *stack_a, t_stack *stack_b, t_bool print);
void    inst_rraf(t_stack *stack_a, t_stack *stack_b, t_bool print, t_bool plz);
void    inst_rrb(t_stack *stack_a, t_stack *stack_b, t_bool print);
void    inst_rrbf(t_stack *stack_a, t_stack *stack_b, t_bool print, t_bool plz);
void    inst_rrr(t_stack *stack_a, t_stack *stack_b, t_bool print);

t_bool	is_ok(t_stack *stack_a, t_stack *stack_b);
t_bool	is_empty(t_stack *stack);
t_bool	is_sorted(t_stack *stack);
t_bool	is_rsorted(t_stack *stack);

void    mem_clean(t_stack *stack_a, t_stack *stack_b);

#endif
