/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:09:05 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/10 15:03:56 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

int main(void)
{
	t_list *top_a;
    t_list *top_b;
	int i;

	i = 0;
    top_a = NULL;
    top_b = NULL;
	{
		ft_lstadd_back(&top_a,ft_lstnew(0));
		ft_lstadd_back(&top_a,ft_lstnew(4));
		ft_lstadd_back(&top_a,ft_lstnew(6));
		ft_lstadd_back(&top_a,ft_lstnew(1));
		ft_lstadd_back(&top_a,ft_lstnew(2));
		ft_lstadd_back(&top_a,ft_lstnew(10));
		ft_lstadd_back(&top_a,ft_lstnew(7));
		ft_lstadd_back(&top_a,ft_lstnew(3));
		ft_lstadd_back(&top_a,ft_lstnew(8));
		ft_lstadd_back(&top_a,ft_lstnew(9));
	}
	{
		ft_lstadd_back(&top_b,ft_lstnew(0));
		ft_lstadd_back(&top_b,ft_lstnew(4));
		ft_lstadd_back(&top_b,ft_lstnew(6));
		ft_lstadd_back(&top_b,ft_lstnew(1));
		ft_lstadd_back(&top_b,ft_lstnew(2));
		ft_lstadd_back(&top_b,ft_lstnew(10));
		ft_lstadd_back(&top_b,ft_lstnew(10));
		ft_lstadd_back(&top_b,ft_lstnew(7));
		ft_lstadd_back(&top_b,ft_lstnew(3));
		ft_lstadd_back(&top_b,ft_lstnew(8));
		ft_lstadd_back(&top_b,ft_lstnew(9));
	}
	display(top_b);
	find_position(top_a, top_b);
	return 0;
}