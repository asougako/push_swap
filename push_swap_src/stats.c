#include "push_swap.h"
#include "shared.h"

int32_t	*get_val(t_stack *stack, uint64_t index)
{
	return(*((*stack).stack + index - 0));
}

int32_t	*get_min(t_stack *stack)
{
	int32_t	index;
	int32_t	*min;

	if (*((*stack).stack + 0) == NULL)
		return(NULL);
	index = 1;
	min = *((*stack).stack + 0);
	while (index < (*stack).len)
	{
		if (min > *((*stack).stack + index))
		{
			min = *((*stack).stack + index);
		}
		index++;
	}
	return(min);
}

int32_t	*get_max(t_stack *stack)
{
}

int32_t	*get_med(t_stack *stack)
{
}

