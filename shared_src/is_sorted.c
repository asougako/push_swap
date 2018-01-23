#include "checker.h"

t_bool	is_both_sorted(t_list *stack_a, t_list *stack_b)
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

t_bool	is_sorted(t_list *stack)
{
	int prev;
	int index;

	if (stack == NULL)
		return(false);
	index = 0;
	while (stack != NULL)
	{
		if (*(int*)((*stack).content) <= prev && index != 0)
		{
			return(false);
		}
		prev = *(int*)((*stack).content);
		stack = (*stack).next;
		index = 1;
	}
	return(true);
}

t_bool	is_rsorted(t_list *stack)
{
	int prev;
	int index;

	if (stack == NULL)
		return(false);
	index = 0;
	while (stack != NULL)
	{
		if (*(int*)((*stack).content) >= prev && index != 0)
		{
			return(false);
		}
		prev = *(int*)((*stack).content);
		stack = (*stack).next;
		index = 1;
	}
	return(true);
}
