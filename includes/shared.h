#ifndef SHARED_H
#define SHARED_H

#include "libft.h"
#include "ft_printf.h"

/*Prototypes*/
int		parse_args(int argc, char *argv[], t_list **stack);
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
t_bool	is_sorted(t_list *stack_a, t_list *stack_b);
void    mem_clean(t_list **stack_a, t_list **stack_b);

#endif
