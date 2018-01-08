#include "checker.h"
#include "shared.h"

void	print_stacks(char *inst, t_list *stack_a, t_list *stack_b, uint64_t opt)
{
	if (opt & OPT_V)
	{
		ft_printf("instruction: %s\n", inst);
		while ((stack_a != NULL) || (stack_b != NULL))
		{
			if (stack_a != NULL)
			{
				ft_printf("\t%d", *(int*)((*stack_a).content));
				stack_a = (*stack_a).next;
			}
			else
				ft_printf("\t");
			if (stack_b != NULL)
			{
				ft_printf("\t%d\n", *(int*)((*stack_b).content));
				stack_b = (*stack_b).next;
			}
			else
				ft_printf("\t\n");
		}
		ft_printf("------------------------\n\ta\tb\n\n");
	}
}

static int check_inst(char *inst, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(inst, "sa") == 0)
		inst_sa(stack_a, stack_b);
	else if (ft_strcmp(inst, "sb") == 0)
		inst_sb(stack_a, stack_b);
	else if (ft_strcmp(inst, "ss") == 0)
		inst_ss(stack_a, stack_b);
	else if (ft_strcmp(inst, "pa") == 0)
		inst_pa(stack_a, stack_b );
	else if (ft_strcmp(inst, "pb") == 0)
		inst_pb(stack_a, stack_b);
	else if (ft_strcmp(inst, "ra") == 0)
		inst_ra(stack_a, stack_b);
	else if (ft_strcmp(inst, "rb") == 0)
		inst_rb(stack_a, stack_b);
	else if (ft_strcmp(inst, "rr") == 0)
		inst_rr(stack_a, stack_b);
	else if (ft_strcmp(inst, "rra") == 0)
		inst_rra(stack_a, stack_b);
	else if (ft_strcmp(inst, "rrb") == 0)
		inst_rrb(stack_a, stack_b);
	else if (ft_strcmp(inst, "rrr") == 0)
		inst_rrr(stack_a, stack_b);
	else
		return(-1);
	return(0);
}

int		exec_inst(t_list **stack_a, t_list **stack_b, uint64_t opt)
{
	char *line;

	print_stacks("init", *stack_a, *stack_b, opt);
	while (get_next_line(0, &line) == 1)
	{
		if (check_inst(line, stack_a, stack_b) == -1)
		{
			ft_strdel(&line);
			ft_printf("Error: bad instruction.\n");
			return(-1);
		}
		print_stacks(line, *stack_a, *stack_b, opt);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return(0);
}

uint64_t	parse_opt(int argc, char *argv[])
{
	uint64_t opt;

	opt = 0;
	while (*argv)
	{
		if (ft_strcmp(*argv, "-v") == 0)
		{
			opt |= OPT_V;
			*argv = ft_strdup("\0");
		}
		else if (ft_strcmp(*argv, "-c") == 0)
		{
			opt |= OPT_C;
			*argv = ft_strdup("\0");
		}
		argv++;
	}
	return(opt);
}

int		main(int argc, char *argv[])
{
	uint64_t	opt;
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	opt = parse_opt(argc, argv);
	if (parse_args(argc, argv, &stack_a) == 0)
	{
		exec_inst(&stack_a, &stack_b, opt);
		check_if_sorted(stack_a, stack_b);
	}
	mem_clean(&stack_a, &stack_b);
	return(0);
}
