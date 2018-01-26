#include "shared.h"

void	inst_pa(t_stack *stack_a, t_stack *stack_b, t_bool print)
{
	if (*((*stack_b).stack))
	{
		(*stack_a).len++;
		inst_rraf(stack_a, stack_b, false, true);
		*((*stack_a).stack + 0) = *((*stack_b).stack + 0);
		*((*stack_b).stack + 0) = NULL;
		inst_rbf(stack_a, stack_b, false, true);
		(*stack_b).len--;
	}
	if(print)
	{
		ft_putendl("pa");
	}
}

void	inst_pb(t_stack *stack_a, t_stack *stack_b, t_bool print)
{

	if (*((*stack_a).stack))
	{
		(*stack_b).len++;
		inst_rrbf(stack_a, stack_b, false, true);
		*((*stack_b).stack + 0) = *((*stack_a).stack + 0);
		*((*stack_a).stack + 0) = NULL;
		inst_raf(stack_a, stack_b, false, true);
		(*stack_a).len--;
	}
	if(print)
	{
		ft_putendl("pb");
	}
}
