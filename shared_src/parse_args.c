#include "shared.h"

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

static int check_duplicate(int val, t_list *stack)
{
	while (stack)
	{
		if (val == *(int*)(*stack).content)
		{
			ft_printf("Error: duplicate argument\n");
			return(-1);
		}
		stack = (*stack).next;
	}
	return(0);
}

int		parse_args(int argc, char *argv[], t_list **stack)
{
	int index;
	int value;
	t_list	*link;

	index = 1;
	while (index < argc)
	{
		//	ft_printf("argv = %s\n", *(argv + index));
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
		if (check_duplicate(value, *stack) != 0)
		{
			return(-1);
		}
		link = ft_lstnew(&value, sizeof(value));
		ft_lstadd_tail(stack, link);
		index++;
	}
	return(0);
}

