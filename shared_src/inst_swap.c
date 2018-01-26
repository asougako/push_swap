#include "shared.h"

#define STACK(ST, IN) *((*stack_##ST).stack + IN)
void	inst_sa(t_stack *stack_a, t_stack *stack_b, t_bool print)
{
	if (*((*stack_a).stack + 0) && *((*stack_a).stack + 1))
	{
		STACK(a, 0) = (int32_t*)((uint64_t)STACK(a, 0) ^ (uint64_t)STACK(a, 1));
		STACK(a, 1) = (int32_t*)((uint64_t)STACK(a, 1) ^ (uint64_t)STACK(a, 0));
		STACK(a, 0) = (int32_t*)((uint64_t)STACK(a, 0) ^ (uint64_t)STACK(a, 1));
	}
	if (print)
	{
		ft_putendl("sa");
	}
}
void	inst_sb(t_stack *stack_a, t_stack *stack_b, t_bool print)
{
	if (*((*stack_b).stack + 0) && *((*stack_b).stack + 1))
	{
		STACK(b, 0) = (int32_t*)((uint64_t)STACK(b, 0) ^ (uint64_t)STACK(b, 1));
		STACK(b, 1) = (int32_t*)((uint64_t)STACK(b, 1) ^ (uint64_t)STACK(b, 0));
		STACK(b, 0) = (int32_t*)((uint64_t)STACK(b, 0) ^ (uint64_t)STACK(b, 1));
	}
	if(print)
	{
		ft_putendl("sb");
	}
}

void	inst_ss(t_stack *stack_a, t_stack *stack_b, t_bool print)
{
	inst_sa(stack_a, stack_b, false);
	inst_sb(stack_a, stack_b, false);
	if(print)
	{
		ft_putendl("ss");
	}
}
