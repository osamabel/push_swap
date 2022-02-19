CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f
NAME = libft.a

SRCS = 	ft_abs.c\
		ft_atol.c\
		ft_display_stack.c\
		ft_free_list.c\
		ft_get_max_list.c\
		ft_get_min_list.c\
		ft_get_node_position.c\
		ft_get_node.c\
		ft_isdigit.c\
		ft_lstadd_back.c\
		ft_lstlast.c\
		ft_lstnew.c\
		ft_lstsize.c\
		ft_max_arr.c\
		ft_min_arr.c\
		ft_print_func.c\
		ft_printf.c\
		ft_split.c\
		ft_strdup.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strtrim.c\
		ft_maz_two_number.c\
		get_next_line_utils.c\
		get_next_line.c\
		ft_substr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all