#include "push_swap.h"
#include "shared.h"

t_bool		is_sorted(t_list **stack_a, t_list **stack_b)
{
	
	return(true);
}

int		algo1(t_list **stack_a, t_list **stack_b)
{
	int		mv_count;

	mv_count = 0;

	while (is_sorted(stack_a, stack_b) == false)
	{

		mv_count++;
	}


	return(mv_count);
}

int		main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	uint64_t	mv_count;

	stack_a = NULL;
	stack_b = NULL;
	if (parse_args(argc, argv, &stack_a) == 0)
	{
		mv_count = algo1(&stack_a, &stack_b);
		ft_printf("mv = %d\n", mv_count);
	}
	mem_clean(&stack_a, &stack_b);
	return(0);
}
