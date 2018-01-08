#include "shared.h"

void	inst_rra(t_list **stack_a, t_list **stack_b)
{
	t_list *before_last;

	if (*stack_a)
	{
		if ((**stack_a).next)
		{
			before_last = *stack_a;
			while ((*(*before_last).next).next)
			{
				before_last = (*before_last).next;
			}
			(*(*before_last).next).next = *stack_a;
			*stack_a = (*before_last).next;
			(*before_last).next = NULL;
		}
	}
}

void	inst_rrb(t_list **stack_a, t_list **stack_b)
{
	t_list *before_last;

	if (*stack_b)
	{
		if ((**stack_b).next)
		{
			before_last = *stack_b;
			while ((*(*before_last).next).next)
			{
				before_last = (*before_last).next;
			}
			(*(*before_last).next).next = *stack_b;
			*stack_b = (*before_last).next;
			(*before_last).next = NULL;
		}
	}
}

void	inst_rrr(t_list **stack_a, t_list **stack_b)
{
	inst_rra(stack_a, stack_b);
	inst_rrb(stack_a, stack_b);
}
