/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:26:31 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/19 16:17:34 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

int	apply_good_instruction(char	*instrc, t_list **top_a, t_list **top_b)
{
	int	len;

	len = ft_strlen(instrc);
	if (!ft_strncmp(instrc, "sa\n", len))
		return (sa(top_a));
	if (!ft_strncmp(instrc, "sb\n", len))
		return (sb(top_b));
	if (!ft_strncmp(instrc, "ss\n", len))
		return (ss(top_a, top_b));
	if (!ft_strncmp(instrc, "ra\n", len))
		return (ra(top_a));
	if (!ft_strncmp(instrc, "rb\n", len))
		return (rb(top_b));
	if (!ft_strncmp(instrc, "rr\n", len))
		return (rr(top_a, top_b));
	if (!ft_strncmp(instrc, "rra\n", len))
		return (rra(top_a));
	if (!ft_strncmp(instrc, "rrb\n", len))
		return (rrb(top_b));
	if (!ft_strncmp(instrc, "rrr\n", len))
		return (rrr(top_a, top_b));
	if (!ft_strncmp(instrc, "pa\n", len))
		return (pa(top_a, top_b));
	if (!ft_strncmp(instrc, "pb\n", len))
		return (pb(top_a, top_b));
	return (0);
}

int	check_list(t_list *top_a, t_list *top_b)
{
	while (top_a->next && top_a->content < top_a->next->content)
		top_a = top_a->next;
	return (top_b == NULL && top_a->next == NULL);
}

int	main(int argc, char *argv[])
{
	t_list	*top_a;
	t_list	*top_b;
	char	*instruction;

	top_a = NULL;
	top_b = NULL;
	if (parsing_argument(argc, argv, &top_a))
	{
		instruction = get_next_line(0);
		while (instruction)
		{
			if (!apply_good_instruction(instruction, &top_a, &top_b))
			{
				free_list(&top_a);
				free_list(&top_b);
				return (0);
			}
			free(instruction);
			instruction = get_next_line(0);
		}
	}
	else
		write(1, "Error\n", 6);
	if (top_a && check_list(top_a, top_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_list(&top_a);
	return 0;
}