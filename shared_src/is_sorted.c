#include "checker.h"
#include "shared.h"

t_bool	is_ok(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) && is_empty(stack_b))
		return(true);
	return(false);
}

t_bool	is_empty(t_stack *stack)
{
	return((*stack).len == 0? true: false);
}

t_bool	is_sorted(t_stack *stack)
{
	int32_t	index;
	int32_t	tmp;

	if (is_empty(stack) == false)
	{
		index = 1;
		tmp = **((*stack).stack + 0);
		while (index < (*stack).len)
		{
			if (tmp >= **((*stack).stack + index))
			{
				return(false);
			}
			tmp = **((*stack).stack + index);
			index++;
		}
		return(true);
	}
	return(false);
}

t_bool	is_rsorted(t_stack *stack)
{
	int32_t	index;
	int32_t	tmp;

	if (is_empty(stack) == false)
	{
		index = 1;
		tmp = **((*stack).stack + 0);
		while (index < (*stack).len)
		{
			if (tmp <= **((*stack).stack + index))
			{
				return(false);
			}
			tmp = **((*stack).stack + index);
			index++;
		}
		return(true);
	}
	return(false);
}
