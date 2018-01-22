#include "push_swap.h"
#include "shared.h"
#include <unistd.h>

int32_t	get_stack_val(t_list *stack, uint64_t index)
{
	while (index > 0)
	{
		stack = (*stack).next;
		index--;
	}
	return(*(int*)((*stack).content));
}

void	get_stack_min(t_list *stack, int32_t *min)
{
	min = (int32_t*)(*stack).content;
	if (min == NULL)
	{
		return;
	}
	while (stack)
	{
		if (*min > *(int32_t*)(*stack).content)
		{
			min = (int32_t*)(*stack).content;
		}
		stack = (*stack).next;
	}
}

int		algo1(t_list **stack_a, t_list **stack_b)
{
	int		inst_count;
	int		*min;

	inst_count = 0;
	while (is_sorted(*stack_a, *stack_b) == false)
	{
		sleep(3);

		get_stack_min(*stack_a, min);

		//	if a[0] == min: pb
		dprintf(2, "min_a = %d\n", *min);
		if (get_stack_val(*stack_a, 0) == *min)
		{
			inst_pb(stack_a, stack_b, true);
		}
//		else if (get_stack_val(*stack_a, 0) > get_stack_val(*stack_a, 1))
//		{
//			inst_sa(stack_a, stack_b, true);
//		}
		else
		{
			inst_rra(stack_a, stack_b, true);
		}
		inst_count++;
	}
	return(inst_count);
}

int		main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	uint64_t	inst_count;

	stack_a = NULL;
	stack_b = NULL;
	if (parse_args(argc, argv, &stack_a) == 0)
	{
		inst_count = algo1(&stack_a, &stack_b);
		dprintf(2, "mv = %llu\n", inst_count);
	}
	mem_clean(&stack_a, &stack_b);
	return(0);
}
