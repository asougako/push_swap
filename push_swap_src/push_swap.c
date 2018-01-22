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

int		get_stack_min(t_list *stack)
{
	int64_t	min;
	return(min);
}

int		algo1(t_list **stack_a, t_list **stack_b)
{
	int		inst_count;
	int		min;

	inst_count = 0;
	while (is_sorted(*stack_a, *stack_b) == false)
	{
		dprintf(2, "stack_a[0] = %d\n", get_stack_val(*stack_a, 0));
		dprintf(2, "stack_a[1] = %d\n", get_stack_val(*stack_a, 1));
		if (get_stack_val(*stack_a, 0) > get_stack_val(*stack_a, 1))
		{
			inst_sa(stack_a, stack_b, true);
		}
		inst_ra(stack_a, stack_b, true);
		inst_count++;
		sleep(1);
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
		ft_printf("mv = %d\n", inst_count);
	}
	mem_clean(&stack_a, &stack_b);
	return(0);
}
