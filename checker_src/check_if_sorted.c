#include "checker.h"

void	check_if_sorted(t_list *stack_a, t_list *stack_b)
{
	int prev;
	int index;

	index = 0;
	if (stack_b != NULL)
	{
		ft_printf("KO");
		return;
	}

	while (stack_a != NULL)
	{
//		ft_printf("%d\n", *(int*)((*stack_a).content)   );
		if (*(int*)((*stack_a).content) <= prev && index != 0)
		{
			ft_printf("KO");
			return;
		}
		prev = *(int*)((*stack_a).content);
		stack_a = (*stack_a).next;
		index = 1;
	}
	ft_printf("OK");
}
