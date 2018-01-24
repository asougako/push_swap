#include "push_swap.h"
#include "shared.h"
#include <unistd.h>

#define STACKS t_list **stack_a, t_list **stack_b
void	get_stack_val(t_list *stack, uint64_t index, int32_t **buff)
{
	*buff = NULL;
	if (stack == NULL)
	{
		return;
	}
	while (index > 0)
	{
		stack = (*stack).next;
		if (stack == NULL)
		{
			return;
		}
		index--;
	}
	*buff = (int*)((*stack).content);
}

void	get_stack_min(t_list *stack, int32_t **min)
{
	*min = NULL;
	if (stack == NULL)
	{
		return;
	}
	*min = (int32_t*)(*stack).content;
	while (stack)
	{
		if (**min > *(int32_t*)(*stack).content)
		{
			*min = (int32_t*)(*stack).content;
		}
		stack = (*stack).next;
	}
	//dprintf(2, "min = %d\n", **min);
}

t_bool	p1r1(t_list **stack_a, t_list **stack_b)
{
	int32_t		*min;
	int32_t		*buff;

	get_stack_min(*stack_a, &min);
	get_stack_val(*stack_a, 0, &buff);
	if (buff == NULL || min == NULL)
	{
		return(false);
	}
	if (*buff == *min)
	{
		inst_pb(stack_a, stack_b, true);
		return (true);
	}
	return (false);
}

t_bool	p1r2(t_list **stack_a, t_list **stack_b)
{
	int32_t		*min;
	int32_t		*buff1;
	int32_t		*buff2;

	get_stack_min(*stack_a, &min);
	get_stack_val(*stack_a, 0, &buff1);
	get_stack_val(*stack_a, 1, &buff2);
	if (buff1 == NULL || buff2 == NULL)
	{
		return(false);
	}
	if (*buff1 > *buff2)
	{
		inst_sa(stack_a, stack_b, true);
		return (true);
	}
	return (false);
}

t_bool	p1r3(t_list **stack_a, t_list **stack_b)
{
	int32_t	*buff1;

	get_stack_val(*stack_a, 3, &buff1);
	if (buff1 == NULL && is_sorted(*stack_a) == true)
	{
		return(true);
	}
	return(false);
}

t_bool	defaut(t_list **stack_a, t_list **stack_b)
{
	inst_rra(stack_a, stack_b, true);
	return(true);
}

int		phase1(t_list **stack_a, t_list **stack_b)
{
	int		ret;
	char	*buff;
	int		inst_count = 0;

	while ((is_rsorted(*stack_b) == false) || *stack_a != NULL)
	{

		while ((ret = get_next_line(0, &buff)) <= 0);
		ft_strdel(&buff);
		//		dprintf(2, "phase1...\n");
		//		dprintf(2, "stack_a=%p\n", *stack_a);
		if (p1r3(stack_a, stack_b))		// if a[0] == min: pb
			break;
		else if(p1r2(stack_a, stack_b));				// if a[0] > a[1]: sa
		else if (p1r1(stack_a, stack_b));		// if a[0] == min: pb
		else if(defaut(stack_a, stack_b));
		inst_count++;
	}
	return(inst_count);
}

t_bool	p2r1(t_list **stack_a, t_list **stack_b)
{
	inst_pa(stack_a, stack_b, true);
	return(true);
}

int		phase2(t_list **stack_a, t_list **stack_b)
{
	int		inst_count = 0;

	while (is_both_sorted(*stack_a, *stack_b) == false)
	{
		dprintf(2, "phase2...\n");
		p2r1(stack_a, stack_b);
		inst_count++;
	}
	return(inst_count);
}

int		algo1(t_list **stack_a, t_list **stack_b)
{
	int		inst_count = 0;

	inst_count += phase1(stack_a, stack_b);
	inst_count += phase2(stack_a, stack_b);
	dprintf(2, "Algo 1 executed in %d instructions\n", inst_count);
}

/*
 *	Calculer la mediane
 *	Phase1: while stack_a non trie && stack_b non reverse trie
 *	Rule: si a[0] < med: pb
 *	Rule: si a[0] > a[1]: sa
 *	Rule> a[1]: sa
 *	default: 
 */

int		main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	uint32_t	inst_count;

	stack_a = NULL;
	stack_b = NULL;
	if (parse_args(argc, argv, &stack_a) == 0)
	{
		inst_count = algo1(&stack_a, &stack_b);
	}
	mem_clean(&stack_a, &stack_b);
	return(0);
}
