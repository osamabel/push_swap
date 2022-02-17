/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:09:05 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/17 15:22:48 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

void	push_swap(t_list **top_a, t_list **top_b)
{
	int	*lis;

	lis = NULL;
	lis = largest_increasing_sequence(*top_a, lis);
	separet_lis(top_a, top_b, lis);
	free(lis);
	while (*top_b)
		find_position(top_a, top_b);
	order_list_by_min(top_a);
}

int	main(int argc, char *argv[])
{
	t_list	*top_a;
	t_list	*top_b;

	top_a = NULL;
	top_b = NULL;
	if (parsing_argument(argc, argv, &top_a))
		push_swap(&top_a, &top_b);
	else
		write(1, "Error\n", 6);
	display(top_a);
	return (0);
}
