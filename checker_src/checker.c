#include "checker.h"
#include "shared.h"

void	print(char *inst, t_stack *stack_a, t_stack *stack_b, uint64_t opt)
{
	int32_t index;

	index = 0;
	if (opt & OPT_V)
	{
		ft_printf("instruction: %s\n", inst);
		while ((*((*stack_a).stack + index) != NULL)\
				|| (*((*stack_b).stack + index) != NULL))
		{
			if (*((*stack_a).stack + index) != NULL)
				ft_printf("\t%d", **((*stack_a).stack + index));
			else
				ft_printf("\t");
			if (*((*stack_b).stack + index) != NULL)
				ft_printf("\t%d\n", **((*stack_b).stack + index));
			else
				ft_printf("\t\n");
			index++;
		}
		ft_printf("-------------------------\n\ta\tb\n\n");
	}
}

static int check_inst(char *inst, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(inst, "sa") == 0)
		inst_sa(stack_a, stack_b, false);
	else if (ft_strcmp(inst, "sb") == 0)
		inst_sb(stack_a, stack_b, false);
	else if (ft_strcmp(inst, "ss") == 0)
		inst_ss(stack_a, stack_b, false);
	else if (ft_strcmp(inst, "pa") == 0)
		inst_pa(stack_a, stack_b, false);
	else if (ft_strcmp(inst, "pb") == 0)
		inst_pb(stack_a, stack_b, false);
	else if (ft_strcmp(inst, "ra") == 0)
		inst_ra(stack_a, stack_b, false);
	else if (ft_strcmp(inst, "rb") == 0)
		inst_rb(stack_a, stack_b, false);
	else if (ft_strcmp(inst, "rr") == 0)
		inst_rr(stack_a, stack_b, false);
	else if (ft_strcmp(inst, "rra") == 0)
		inst_rra(stack_a, stack_b, false);
	else if (ft_strcmp(inst, "rrb") == 0)
		inst_rrb(stack_a, stack_b, false);
	else if (ft_strcmp(inst, "rrr") == 0)
		inst_rrr(stack_a, stack_b, false);
	else
		return(-1);
	return(0);
}

int		exec_insts(t_stack *stack_a, t_stack *stack_b, uint64_t opt)
{
	char *line;

	print("init", stack_a, stack_b, opt);
	while (get_next_line(0, &line) == 1)
	{
		if (check_inst(line, stack_a, stack_b) == -1)
		{
			ft_strdel(&line);
			ft_printf("Error: bad instruction.\n");
			return(-1);
		}
		print(line, stack_a, stack_b, opt);
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
	t_stack		*stack_a;
	t_stack		*stack_b;

	opt = parse_opt(argc, argv);
	stack_a = new_stack(argc);
	stack_b = new_stack(argc);

	if (parse_args(argc, argv, stack_a, stack_b) == 0)
	{
		exec_insts(stack_a, stack_b, opt);
		if (is_ok(stack_a, stack_b) == false)
		{
			ft_printf("KO\n");
		}
		else
		{
			ft_printf("OK\n");
		}
	}

	mem_clean(stack_a, stack_b);
	return(0);
}
