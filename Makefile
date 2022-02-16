CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f
NAME = lib.a

SRCS = list_manipulation/push.c\
	list_manipulation/reverse_rotate.c\
	list_manipulation/rotate.c\
	list_manipulation/swap.c\
	list_manipulation/ft_lstsize.c\
	list_manipulation/ft_lstlast.c\
	list_manipulation/ft_lstadd_back.c\
	list_manipulation/ft_lstnew.c\
	list_manipulation/largest_increasing_sequence.c\
	list_manipulation/separate_ab.c\
	list_manipulation/position_ab.c\
	list_manipulation/order_list_by_min.c\
	list_manipulation/parsing.c\
	list_manipulation/split.c\
	utils/ft_atol.c\
	utils/util.c\

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