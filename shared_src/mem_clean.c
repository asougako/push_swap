#include "shared.h"

void	mem_clean(t_stack *stack_a, t_stack *stack_b)
{
	ft_memdel((void**)&(*stack_a).stack);
	ft_memdel((void**)&stack_a);
	ft_memdel((void**)&(*stack_b).stack);
	ft_memdel((void**)&stack_b);
}
