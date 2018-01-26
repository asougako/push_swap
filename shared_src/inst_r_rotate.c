#include "shared.h"

void	inst_rra(t_stack *stack_a, t_stack *stack_b, t_bool print)
{
	inst_rraf(stack_a, stack_b, print, false);
}

void	inst_rraf(t_stack *stack_a, t_stack *stack_b, t_bool print, t_bool plz)
{
	int32_t *tmp;

	if ((*((*stack_a).stack + 0) && *((*stack_a).stack + 1)) || plz)
	{
		tmp = *((*stack_a).stack + ((*stack_a).len - 1));
		ft_memmove(\
				((*stack_a).stack + 1),\
				((*stack_a).stack + 0),\
				(*stack_a).len * sizeof(int32_t*));
		*((*stack_a).stack + 0) = tmp;
		*((*stack_a).stack + ((*stack_a).len)) = NULL;
	}
	if (print)
	{
		ft_putendl("ra");
	}
}

void	inst_rrb(t_stack *stack_a, t_stack *stack_b, t_bool print)
{
	inst_rrbf(stack_a, stack_b, print, false);
}

void	inst_rrbf(t_stack *stack_a, t_stack *stack_b, t_bool print, t_bool plz)
{
	int32_t *tmp;

	if ((*((*stack_b).stack + 0) && *((*stack_b).stack + 1)) || plz)
	{
		tmp = *((*stack_b).stack + ((*stack_b).len - 1));
		ft_memmove(\
				((*stack_b).stack + 1),\
				((*stack_b).stack + 0),\
				(*stack_b).len * sizeof(int32_t*));
		*((*stack_b).stack + 0) = tmp;
		*((*stack_b).stack + ((*stack_b).len)) = NULL;
	}
	if (print)
	{
		ft_putendl("rb");
	}
}

void	inst_rrr(t_stack *stack_a, t_stack *stack_b, t_bool print)
{
	inst_rra(stack_a, stack_b, false);
	inst_rrb(stack_a, stack_b, false);
	if (print)
	{
		ft_putendl("rrr");
	}
}

