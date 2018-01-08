#ifndef CHECKER_H
#define CHECKER_H

#include "libft.h"
#include "ft_printf.h"

#define OPT_V 0x01
#define OPT_C 0x02

/*Prototypes*/
void    check_if_sorted(t_list *stack_a, t_list *stack_b);
void    mem_clean(t_list **stack_a, t_list **stack_b);

#endif
