CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f
NAME = lib.a

SRCS = list_manipulation/push_a.c list_manipulation/push_b.c\
	list_manipulation/reverse_rotate_a.c list_manipulation/reverse_rotate_b.c\
	list_manipulation/rotate_a.c list_manipulation/rotate_b.c\
	list_manipulation/swap_a.c list_manipulation/swap_b.c\
	list_manipulation/ft_lstsize.c list_manipulation/ft_lstlast.c\
	list_manipulation/ft_lstadd_back.c list_manipulation/ft_lstnew.c\
	utils/ft_atoi.c list_manipulation/largest_increasing_sequence.c\
	list_manipulation/separate_ab.c 
OBJS = $(SRCS:.c=.o)

all:	$(NAME) compile

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

compile :
	@$(CC) $(CFLAGS) main.c $(NAME) -o push_swap
	@./push_swap 331 142 590 737 310 150 579 834 504 255 589 20 480 334 571 132 660

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) push_swap

re: fclean all