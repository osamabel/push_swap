CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f
NAME = push_swap


SRCS =  list_manipulation/best_case.c\
		list_manipulation/largest_increasing_sequence.c\
		list_manipulation/order_list_by_min.c\
		list_manipulation/parsing.c\
		list_manipulation/position_ab.c\
		list_manipulation/push.c\
		list_manipulation/reverse_rotate.c\
		list_manipulation/rotate.c\
		list_manipulation/separate_ab.c\
		list_manipulation/sorting.c\
		list_manipulation/swap.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) main.c
	make -C libft
	$(CC) $(CFLAGS) main.c $(OBJS) -L libft -lft -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

bonus : checker

checker : $(OBJS) checker.c
	make -C libft
	$(CC) $(CFLAGS) checker.c $(OBJS) -L libft -lft -o checker

clean:
	make clean -C libft
	@$(RM) $(OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)
	$(RM) push_swap
	$(RM) checker

re: fclean all
