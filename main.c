/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:09:05 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/13 16:02:27 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

// int main(void)
int main(int argc, char *argv[])
{
	t_list *top_a;
    t_list *top_b;
	int i;

	i = 1;
    top_a = NULL;
    top_b = NULL;
	while (i < argc)
	{
		ft_lstadd_back(&top_a,ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	// {
	// 	ft_lstadd_back(&top_a,ft_lstnew(6));
	// 	ft_lstadd_back(&top_a,ft_lstnew(48));
	// 	ft_lstadd_back(&top_a,ft_lstnew(26));
	// 	ft_lstadd_back(&top_a,ft_lstnew(75));
	// 	ft_lstadd_back(&top_a,ft_lstnew(5));
	// 	ft_lstadd_back(&top_a,ft_lstnew(89));
	// 	ft_lstadd_back(&top_a,ft_lstnew(100));
	// 	ft_lstadd_back(&top_a,ft_lstnew(94));
	// 	ft_lstadd_back(&top_a,ft_lstnew(68));
	// 	ft_lstadd_back(&top_a,ft_lstnew(41));
	// 	ft_lstadd_back(&top_a,ft_lstnew(95));
	// 	ft_lstadd_back(&top_a,ft_lstnew(83));
	// 	ft_lstadd_back(&top_a,ft_lstnew(76));
	// 	ft_lstadd_back(&top_a,ft_lstnew(17));
	// 	ft_lstadd_back(&top_a,ft_lstnew(74));
	// 	ft_lstadd_back(&top_a,ft_lstnew(10));

	// }
	order_list_by_min(&top_a);
	int *list = largest_increasing_sequence(top_a);
	separet_lis(&top_a, &top_b, list);
	free(list);
	//while (top_b)
		find_position(&top_a, &top_b);
	order_list_by_min(&top_a);
	display(top_a);
	return 0;
}
