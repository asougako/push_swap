.PHONY: clean, fclean, re, proper
.SUFFIXES:

CC = gcc
CF = -Wall -Wextra - Werror
RM = /bin/rm
INC_DIR = -I ./includes/ -I ./libft/includes/

PS_NAME	= push_swap
PS_SRC_FOLD = push_swap_src/
PS_SRC_FILES = push_swap.c
PS_SRC = $(addprefix $(PS_SRC_FOLD), $(PS_SRC_FILES))

CHK_NAME = checker
CHK_SRC_FOLD = checker_src/
CHK_SRC_FILES = checker.c
CHK_SRC = $(addprefix $(CHK_SRC_FOLD), $(CHK_SRC_FILES))

SHARED_SRC_FOLD = shared_src/
SHARED_SRC_FILES = inst_swap.c	inst_push.c		inst_rotate.c	inst_r_rotate.c\
				   parse_args.c	is_sorted.c		mem_clean.c
SHARED_SRC = $(addprefix $(SHARED_SRC_FOLD), $(SHARED_SRC_FILES))

all: $(PS_NAME) $(CHK_NAME)

debug:
#	$(CC) -g -o $(PS_NAME) $(PS_SRC) $(SHARED_SRC) -I includes -I libft/includes libft/libft.a\
		-fsanitize=address
	$(CC) -g -o $(CHK_NAME) $(CHK_SRC) $(SHARED_SRC) -I includes -I libft/includes libft/libft.a\
		-fsanitize=address

$(PS_NAME): $(PS_SRC) $(SHARED_SRC)

$(CHK_NAME): $(CHK_SRC) $(SHARED_SRC)

clean:
	rm $(PS_NAME) $(CHK_NAME)

re: clean all
