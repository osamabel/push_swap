CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f
NAME = lib.a

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
		list_manipulation/swap.c\
		libft/ft_abs.c\
		libft/ft_atol.c\
		libft/ft_display_stack.c\
		libft/ft_free_list.c\
		libft/ft_get_max_list.c\
		libft/ft_get_min_list.c\
		libft/ft_get_node_position.c\
		libft/ft_get_node.c\
		libft/ft_isdigit.c\
		libft/ft_lstadd_back.c\
		libft/ft_lstlast.c\
		libft/ft_lstnew.c\
		libft/ft_lstsize.c\
		libft/ft_max_arr.c\
		libft/ft_min_arr.c\
		libft/ft_print_func.c\
		libft/ft_printf.c\
		libft/ft_split.c\
		libft/ft_strdup.c\
		libft/ft_strlcpy.c\
		libft/ft_strlen.c\
		libft/ft_strtrim.c\
		libft/ft_maz_two_number.c \
		libft/ft_substr.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME) compile

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

.c.o:
	@$(CC) $(CFLAGS) -o $@ -c $<

compile :
	@$(CC) $(CFLAGS) main.c $(NAME) -o push_swap

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) push_swap

re: fclean all