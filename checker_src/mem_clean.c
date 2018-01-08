#include "checker.h"

static	void	stack_destructor(void *content, size_t size)
{
	(void)size;
	ft_memdel(&content);
}

void	mem_clean(t_list **stack_a, t_list **stack_b)
{
	ft_lstdel(stack_a, stack_destructor);
	ft_lstdel(stack_b, stack_destructor);
}
