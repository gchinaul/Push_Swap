NAME = push_swap
BONUS = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -pedantic -ansi
RM = rm -f
INCLUDES = -I.

SRC_DIR = src
LIBFT = $(SRC_DIR)/libft.c

SRCS_PUSH_SWAP = \
    src/main.c \
    src/node.c \
    src/stack.c \
    src/stack_size.c \
    src/optimize/execute.c \
    src/optimize/op_exec.c \
    src/op_push.c \
    src/op_swap.c \
    src/op_rotate.c \
    src/op_reverse.c \
    src/parser.c \
    src/sort_small.c \
    src/turk/algo_turk.c \
    src/turk/turk_execute.c \
    src/turk/cheapest_move.c \
    src/turk/utils_1.c \
    src/turk/utils_2.c \
    src/libft.c

SRCS_CHECKER = \
    src/checker.c \
    src/node.c \
    src/stack.c \
    src/stack_size.c \
    src/optimize/execute.c \
    src/optimize/op_exec.c \
    src/op_push.c \
    src/op_swap.c \
    src/op_rotate.c \
    src/op_reverse.c \
    src/parser.c \
    src/sort_small.c \
    src/turk/algo_turk.c \
    src/turk/turk_execute.c \
    src/turk/cheapest_move.c \
    src/turk/utils_1.c \
    src/turk/utils_2.c \
    src/libft.c 

OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_PUSH_SWAP)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_PUSH_SWAP) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJS_CHECKER)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_CHECKER) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS_PUSH_SWAP) $(OBJS_CHECKER)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
