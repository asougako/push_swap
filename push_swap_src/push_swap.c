#include "push_swap.h"

t_bool	p1r1(t_stack *stack_a, t_stack *stack_b)
{
	int32_t		*min;
	int32_t		*buff;

	min = get_min(stack_a);
	buff = get_val(stack_a, 0);
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

t_bool	p1r2(t_stack *stack_a, t_stack *stack_b)
{
	int32_t		*min;
	int32_t		*buff1;
	int32_t		*buff2;

	min = get_min(stack_a);
	buff1 = get_val(stack_a, 0);
	buff2 = get_val(stack_a, 1);
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

t_bool	p1r3(t_stack *stack_a, t_stack *stack_b)
{
	int32_t	*buff1;

	buff1 = get_val(stack_a, 3);
	if (buff1 == NULL && is_sorted(stack_a) == true)
	{
		return(true);
	}
	return(false);
}

t_bool	defaut(t_stack *stack_a, t_stack *stack_b)
{
	inst_rra(stack_a, stack_b, true);
	return(true);
}

int		phase1(t_stack *stack_a, t_stack *stack_b)
{
	char	*buff;
	int		inst_count = 0;

	while ((is_rsorted(stack_b) == false) || stack_a != NULL)
	{
		while (get_next_line(0, &buff) <= 0);
		ft_strdel(&buff);
		if (p1r3(stack_a, stack_b))			// if a[0] == min: pb
			break;
		else if(p1r2(stack_a, stack_b))
			;	// if a[0] > a[1]: sa
		else if (p1r1(stack_a, stack_b))
			;	// if a[0] == min: pb
		else if(defaut(stack_a, stack_b))
			;
		inst_count++;
	}
	return(inst_count);
}

t_bool	p2r1(t_stack *stack_a, t_stack *stack_b)
{
	inst_pa(stack_a, stack_b, true);
	return(true);
}

int		phase2(t_stack *stack_a, t_stack *stack_b)
{
	char	*buff;
	int		inst_count = 0;

	while (is_ok(stack_a, stack_b) == false)
	{
		while (get_next_line(0, &buff) <= 0);
		ft_strdel(&buff);

		dprintf(2, "phase2...\n");
		p2r1(stack_a, stack_b);
		inst_count++;
	}
	return(inst_count);
}

static uint64_t    parse_opt(int argc, char *argv[])
{
	uint64_t opt;

	opt = 0;
	while (*argv)
	{
		if (ft_strcmp(*argv, "-s") == 0)
		{
			opt |= OPT_S;
			*argv = ft_strdup("\0");
		}
		argv++;
	}
	return(opt);
}

void	algo1(t_stack *stack_a, t_stack *stack_b)
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
	uint64_t    opt;
	t_stack     *stack_a;
	t_stack     *stack_b;

	opt = parse_opt(argc, argv);
	stack_a = new_stack(argc);
	stack_b = new_stack(argc);
	if (parse_args(argc, argv, stack_a, stack_b) == 0)
	{
		//algo1(stack_a, stack_b);
	}
	mem_clean(stack_a, stack_b);
	return(0);
}
