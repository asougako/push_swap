#include "shared.h"

void	mem_clean(t_stack *stack_a, t_stack *stack_b)
{
	int index;

	index = 0;
	while (	*((*stack_a).stack + index) != NULL	)
	{
		ft_memdel((void**)&*((*stack_a).stack + index));
		index++;
	}
	index = 0;
	while (	*((*stack_a).stack + index) != NULL	)
	{
		ft_memdel((void**)&*((*stack_a).stack + index));
		index++;
	}
	ft_memdel((void**)&(*stack_a).stack);
	ft_memdel((void**)&(*stack_b).stack);
	ft_memdel((void**)&stack_a);
	ft_memdel((void**)&stack_b);
}
