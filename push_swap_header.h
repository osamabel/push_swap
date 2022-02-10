/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 22:52:39 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/10 16:01:21 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_HEADER_H
#define PUSH_SWAP_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	struct s_list	*prev;
	int			content;
	struct s_list	*next;
}	t_list;

typedef struct s_position
{
	int			pos_a;
	int			helper_a;
	int			pos_b;
	int			position;
}	t_postion;

int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	display(t_list *top);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);

void push(t_list **top_1,t_list **top_2);
void swap(t_list **top);
void reverse(t_list **top);
void rotate(t_list **top);

int	ft_atoi(const char *str);
int	ft_ispace(char c);
int	testlong(unsigned long long nb, int sign);
int all_done(t_list *top);


int *largest_increasing_sequence(t_list *top);
t_list *get_node_by_value(t_list *top, int position);
void	ft_swap_nodes(t_list **top_a, t_list **top_b, int i, int j);
t_list	*get_mid_point(t_list *top,int lo, int hi);
void remove_s(int *tab, int pos,int size);
t_list *get_min_node(t_list *top);
int	max_of_arr(int *list ,int size,int last_max);
int existe(int c, int list[]);
void separet_lis(t_list **top_a, t_list **top_b, int *list);
int is_between(int x, int a, int b);
void find_position(t_list *top_a, t_list *top_b);


#endif