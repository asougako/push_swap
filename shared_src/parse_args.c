#include "shared.h"

/*
 *	Make arg easyer to handle by atoi.
 */
static char *aclean(const char *src)
{
	char *ret;
	char *tmp;
	int index;


	index = 0;
	tmp = (char*)src;
	ret = ft_strnew(ft_strlen(tmp));
	if (*tmp == '-')
	{
		*ret = '-';
		index++;
		tmp++;
	}
	while (*tmp == '0' && *(tmp + 1) != '\0')
	{
		tmp++;
	}
	ft_strcpy(ret + index, tmp);
	if (ft_strcmp(ret, "-0") == 0)
	{
		ft_strdel(&ret);
		ret = ft_strdup("0");
	}
	return(ret);
}

/*
 *	Check if arg is a valid int32_t value.
 */
static int		check_arg(char *arg)
{
	int		intval;
	char	*str_val;
	char	*tmp_val;

	tmp_val = aclean(arg);
	intval = ft_atoi(arg);
	str_val = ft_itoa(intval);
	if (ft_strcmp(tmp_val, str_val) != 0)
	{
		ft_printf("Error: bad argument\n");
		ft_strdel(&str_val);
		ft_strdel(&tmp_val);
		return(-1);
	}
	ft_strdel(&str_val);
	ft_strdel(&tmp_val);
	return(0);
}

/*
 *	Check id val already exists.
 */
static int check_duplicate(int val, t_stack *stack_a)
{
//	while (stack_a)
//	{
//		if (val == *(int*)(*stack).content)
//		{
//			ft_printf("Error: duplicate argument\n");
//			return(-1);
//		}
//		stack = (*stack).next;
//	}
	return(0);
}

t_stack	*new_stack(size_t len)
{
	t_stack *stack;

	stack = ft_memalloc(sizeof(*stack));
	(*stack).stack = ft_memalloc(len * sizeof(*(*stack).stack));
	return(stack);
}

/*
 *	Detects errors in argv.
 *	Fill stack a.
 */
int		parse_args(int argc, char *argv[], t_stack *stack_a)
{
	int index;
	int value;

	index = 1;
	while (index < argc)
	{
		if (**(argv + index) == '\0')
		{
			index++;
			continue;
		}
		if (check_arg(*(argv + index)) != 0)
		{
			return(-1);
		}
		value = ft_atoi(*(argv + index));
		if (check_duplicate(value, stack_a) != 0)
		{
			return(-1);
		}
//		link = ft_lstnew(&value, sizeof(value));
//		ft_lstadd_tail(stack, link);
		index++;
	}
	return(0);
}
