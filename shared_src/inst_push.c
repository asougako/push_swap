#include "shared.h"

void	inst_pa(t_stack *stack_a, t_stack *stack_b, t_bool print)
{
	if (*((*stack_a).stack))
	{
		//tmp = *stack_a;
		//*stack_a = *stack_b;
		//*stack_b = (**stack_b).next;
		//(**stack_a).next = tmp;
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
		//tmp = *stack_b;
		//*stack_b = *stack_a;
		//*stack_a = (**stack_a).next;
		//(**stack_b).next = tmp;
	}
	if(print)
	{
		ft_putendl("pb");
	}
}
