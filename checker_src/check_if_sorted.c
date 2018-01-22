#include "checker.h"

void	is_sorted(t_list *stack_a, t_list *stack_b)
{
	int prev;
	int index;

	index = 0;
	if (stack_b != NULL)
	{
		return(false);
	}

	while (stack_a != NULL)
	{
		if (*(int*)((*stack_a).content) <= prev && index != 0)
		{
			return(false);
		}
		prev = *(int*)((*stack_a).content);
		stack_a = (*stack_a).next;
		index = 1;
	}
	return(true);
}
