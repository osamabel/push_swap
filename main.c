/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:09:05 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/12 20:20:23 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

int main(void)
{
	t_list *top_a;
    t_list *top_b;
	int i;

	i = 1;
    top_a = NULL;
    top_b = NULL;
	{
		ft_lstadd_back(&top_a,ft_lstnew(6));
		ft_lstadd_back(&top_a,ft_lstnew(48));
		ft_lstadd_back(&top_a,ft_lstnew(26));
		ft_lstadd_back(&top_a,ft_lstnew(75));
		ft_lstadd_back(&top_a,ft_lstnew(5));
		ft_lstadd_back(&top_a,ft_lstnew(89));
		ft_lstadd_back(&top_a,ft_lstnew(100));
		ft_lstadd_back(&top_a,ft_lstnew(94));
		ft_lstadd_back(&top_a,ft_lstnew(68));
		ft_lstadd_back(&top_a,ft_lstnew(41));
		ft_lstadd_back(&top_a,ft_lstnew(95));
		ft_lstadd_back(&top_a,ft_lstnew(83));
		ft_lstadd_back(&top_a,ft_lstnew(76));
		ft_lstadd_back(&top_a,ft_lstnew(17));
		ft_lstadd_back(&top_a,ft_lstnew(74));
		ft_lstadd_back(&top_a,ft_lstnew(10));

		// ft_lstadd_back(&top_a,ft_lstnew(0));
		// ft_lstadd_back(&top_a,ft_lstnew(4));
		// ft_lstadd_back(&top_a,ft_lstnew(6));
		// ft_lstadd_back(&top_a,ft_lstnew(1));
		// ft_lstadd_back(&top_a,ft_lstnew(2));
		// ft_lstadd_back(&top_a,ft_lstnew(10));
		// ft_lstadd_back(&top_a,ft_lstnew(7));
		// ft_lstadd_back(&top_a,ft_lstnew(3));
		// ft_lstadd_back(&top_a,ft_lstnew(8));
		// ft_lstadd_back(&top_a,ft_lstnew(9));
	}
	display(top_a);
	int *list = largest_increasing_sequence(top_a);
	while (i<=list[0])
	{
		printf("%i ",list[i]);
		i++;
	}
	printf("\n");
	separet_lis(&top_a, &top_b, list);
	free(list);
	printf("A ->");
	display(top_a);
	printf("B ->");
	display(top_b);
	// display(top_b);
	find_position(&top_a, &top_b);
	return 0;
}
