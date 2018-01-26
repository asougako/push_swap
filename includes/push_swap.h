#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include "ft_printf.h"
#include "shared.h"

#define OPT_S 0x01

int32_t *get_val(t_stack *stack, uint64_t index);
int32_t *get_min(t_stack *stack);
int32_t *get_max(t_stack *stack);
int32_t *get_med(t_stack *stack);

#endif
