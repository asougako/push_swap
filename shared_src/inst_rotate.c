#include "shared.h"

void	inst_ra(t_list **stack_a, t_list **stack_b, t_bool print)
{
	t_list *last;

	if (*stack_a)
	{
		last = *stack_a;
		while((*last).next)
		{
			last = (*last).next;
		}
		(*last).next = *stack_a;
		*stack_a = (**stack_a).next;
		(*(*last).next).next = NULL;
	}
	if (print)
		ft_putendl("ra");
}

void	inst_rb(t_list **stack_a, t_list **stack_b, t_bool print)
{
	t_list *last;

	if (*stack_b)
	{
		last = *stack_b;
		while((*last).next)
		{
			last = (*last).next;
		}
		(*last).next = *stack_b;
		*stack_b = (**stack_b).next;
		(*(*last).next).next = NULL;
	}
	if (print)
		ft_putendl("rb");
}

void	inst_rr(t_list **stack_a, t_list **stack_b, t_bool print)
{
	inst_ra(stack_a, stack_b, false);
	inst_rb(stack_a, stack_b, false);
	if (print)
		ft_putendl("rr");
}
