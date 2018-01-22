#include "shared.h"

#define CURRENT ((**stack_a).content)
#define NEXT ((*(**stack_a).next).content)
void	inst_sa(t_list **stack_a, t_list **stack_b, t_bool print)
{
	int *tmp;

	(void)stack_b;
	if (*stack_a)
	{
		if ((**stack_a).next)
		{
			tmp = CURRENT;
			CURRENT = NEXT;
			NEXT = tmp;
		}
	}
	if (print)
		ft_putendl("sa");
}
#undef CURRENT
#undef NEXT

#define CURRENT ((**stack_b).content)
#define NEXT ((*(**stack_b).next).content)
void	inst_sb(t_list **stack_a, t_list **stack_b, t_bool print)
{
	int *tmp;

	(void)stack_a;
	if (*stack_b)
	{
		if ((**stack_b).next)
		{
			tmp = CURRENT;
			CURRENT = NEXT;
			NEXT = tmp;
		}
	}
	if(print)
		ft_putendl("sb");
}
#undef CURRENT
#undef NEXT

void	inst_ss(t_list **stack_a, t_list **stack_b, t_bool print)
{
	inst_sa(stack_a, stack_b, false);
	inst_sb(stack_a, stack_b, false);
	if(print)
		ft_putendl("ss");
}
