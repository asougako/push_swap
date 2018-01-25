#include "shared.h"

void	inst_ra(t_stack *stack_a, t_stack *stack_b, t_bool print)
{
	int32_t *tmp;

	if (*((*stack_a).stack + 0) && *((*stack_a).stack + 1))
	{
		tmp = *((*stack_a).stack + 0);
		ft_memmove(\
				((*stack_a).stack + 0),\
				((*stack_a).stack + 1),\
				(*stack_a).len * sizeof(int32_t*));
		*((*stack_a).stack + (*stack_a).len - 1) = tmp;
	}
	if (print)
	{
		ft_putendl("ra");
	}
}

void	inst_rb(t_stack *stack_a, t_stack *stack_b, t_bool print)
{
	int32_t *tmp;

	if (*((*stack_b).stack + 0) && *((*stack_b).stack + 1))
	{
		tmp = *((*stack_b).stack + 0);
		ft_memmove(\
				((*stack_b).stack + 0),\
				((*stack_b).stack + 1),\
				(*stack_b).len * sizeof(int32_t*));
		*((*stack_b).stack + (*stack_b).len - 1) = tmp;
	}
	if (print)
	{
		ft_putendl("rb");
	}
}

void	inst_rr(t_stack *stack_a, t_stack *stack_b, t_bool print)
{
	inst_ra(stack_a, stack_b, false);
	inst_rb(stack_a, stack_b, false);
	if (print)
	{
		ft_putendl("rr");
	}
}
