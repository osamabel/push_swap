/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 22:52:39 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/17 13:04:51 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_HEADER_H
# define PUSH_SWAP_HEADER_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	struct s_list	*prev;
	int				content;
	int				keep;
	struct s_list	*next;
}	t_list;

typedef struct s_position
{
	int			pos_a;
	int			pos_b;
	int			index;
}	t_postion;

/* LIBFT */
long	ft_atol(const char *str);
int		ft_ispace(char c);
void	display(t_list *top);
void	free_list(t_list **top);
t_list	*get_max_list(t_list *top);
t_list	*get_min_list(t_list *top);
int		get_pos_by_node(t_list *top, t_list *node);
t_list	*get_node_by_value(t_list *top, int position);
int		ft_isdigit(int c);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
int		max_of_arr(int *list, int size, int last_max);
int		min_of_arr(int *tab, int size);
char	**ft_split(char const *s, char c);
char	**str_to_split(char **result, char const *str, char c);
int		free_splited(char **result, int n);
int		wcount(char const *s, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char	*c);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_letter(char const *set, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_abs(int x);
int		max_of_two_number(int a, int b);

/* FT_PRINTF */
int		ft_printf(const char *str, ...);
void	check_char(va_list list, char c, int *len, int *i);
int		put_string(char	*str);
int		put_char(char c);
int		put_number(int n);
int		put_number_u(unsigned int n);
int		putnbr_base(unsigned int nbr, char	*base);
int		put_address(unsigned long nbr, char	*base);

/*LIST_MANIPULATION*/
int		*largest_increasing_sequence(t_list *top_a, int *lis);
t_list	*min_on_top(t_list *top);
void	set_head(t_list **head, t_list **node);
int		*set_list_tab(t_list *top);
void	*ft_memset(int *buf, int c, size_t	len);
void	order_list_by_min(t_list **top);
int		parsing_argument(int argc, char	*argv[], t_list **top_a);
int		verify_args(char **args, t_list **top_a, int size);
int		check_doubles(t_list **top);
void	split_args(char **args, char *argv, int *j);
void	find_position(t_list **top_a, t_list **top_b);
void	set_pos_a(t_list *top_a, t_list *top_b, t_postion *pos, int *tab);
void	set_pos_b(t_list *top_b, t_postion *pos);
int		case_1(t_list *top_a, t_list *top_b, t_postion *pos, int *tab);
int		case_2(t_list *top_a, t_list *top_b, t_postion *pos, int *tab);
void	set_tab(int	*tab, t_postion	*pos);
void	case_3(t_list *top_a, t_postion *pos, int *tab);
int		push(t_list **top_1, t_list **top_2);
int		pa(t_list **top_a, t_list **top_b);
int		pb(t_list **top_a, t_list **top_b);
int		reverse(t_list **top);
int		rrr(t_list **top_a, t_list **top_b);
int		rra(t_list **top_a);
int		rrb(t_list **top_b);
int		rotate(t_list **top);
int		rr(t_list **top_a, t_list **top_b);
int		ra(t_list **top_a);
int		rb(t_list **top_b);
void	separet_lis(t_list **top_a, t_list **top_b, int *list);
int		check_keeped_number(t_list *top);
void	set_keeped_node(t_list *top_a, int *list);
int		is_existe(int c, int list[]);
void	apply_sort(t_list **top_a, t_list **top_b, t_postion *pos, int min);
void	optimisation(t_list **top_a, t_list **top_b, t_postion *pos, int min);
int		swap(t_list **top);
int		ss(t_list **top_a, t_list **top_b);
int		sa(t_list **top_a);
int		sb(t_list **top_b);

#endif