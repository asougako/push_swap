#include "shared.h"

void	inst_pa(t_list **stack_a, t_list **stack_b, t_bool print)
{
	t_list	*tmp;

	if (*stack_b)
	{
		tmp = *stack_a;
		*stack_a = *stack_b;
		*stack_b = (**stack_b).next;
		(**stack_a).next = tmp;
	}
	if(print)
		ft_putendl("pa");
}

void	inst_pb(t_list **stack_a, t_list **stack_b, t_bool print)
{
	t_list	*tmp;

	if (*stack_a)
	{
		tmp = *stack_b;
		*stack_b = *stack_a;
		*stack_a = (**stack_a).next;
		(**stack_b).next = tmp;
	}
	if(print)
		ft_putendl("pb");
}
