/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:31:30 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/09 16:30:29 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

int is_between(int x, int a, int b)
{
	return ((x > a && x < b) || (x < a && x > b));
}

void	set_pos_b(t_list *top_b, t_postion *pos)
{
	int	i;
	int	j;
	t_list *head;

	i = 0;
	j = 0;
	head = top_b;
	while (i <= ft_lstsize(top_b) / 2)
	{
		pos[i].pos_b = j;
		j++;
		i++;
		top_b = top_b->next;
	}
	while (top_b)
	{
		/* code */
	}
	
	
	while (head)
	{
		if (i <= ft_lstsize(top_b) / 2)
		{
			pos[i].pos_b = j;
			j++;
		}
		else if (ft_lstsize(top_b) % 2 != 0 && i - 1 == ft_lstsize(top_b) / 2)
		{
			j++;
			pos[i].pos_b = -j;
			j--;
		}
		else
		{
			pos[i].pos_b = -j;
			j--;
		}
		i++;
		head = head->next;
	}
}

void find_position(t_list *top_a, t_list *top_b)
{
	t_postion *pos;
	//t_list *no;
	int size_b = ft_lstsize(top_b);
	//int size_a = ft_lstsize(top_a);
	int i = 0;
//	int z = 1;
	int j = size_b / 2;
	j *= -1;
	(void)top_a;
	pos = malloc(sizeof(t_postion) * size_b);
	set_pos_b(top_b, pos);
	i = 0;
	while (i < size_b)
	{
		printf(">> %i\n", pos[i].pos_b);
		i++;
	}

	// while (top_b)
	// {
	// 	z = 1;
	// 	// if (i < size_b / 2)
	// 	// 	pos[i].pos_b = i;
	// 	// else
	// 	// {
	// 	// 	pos[i].pos_b = j;
	// 	// 	j++;
	// 	// }
	// 	// find pos_a
	// 	no = ft_lstlast(top_a,1,ft_lstsize(top_a)); // case 1
	// 	if (is_between(top_b->content, top_a->content,no->content))
	// 		pos[i].pos_a = 0;
	// 	else if (z == 1)                            // case 2
	// 	{
	// 		while (z <= size_a / 2)
	// 		{
	// 			if (is_between(top_b->content, top_a->content,top_a->next->content))
	// 			{
	// 				pos[i].pos_a = z;
	// 				break ;
	// 			}
	// 			z++;
	// 			top_a = top_a->next;
	// 		}
	// 	}
	// 	else if (z == size_a / 2)                   // case 3
	// 	{
	// 		z = -z;
	// 		while (top_a->next->content)
	// 		{
	// 			if (is_between(top_b->content, top_a->content,top_a->next->content))
	// 			{
	// 				pos[i].pos_a = z;
	// 				break ;
	// 			}
	// 			z++;
	// 			top_a = top_a->next;
	// 		}
	// 	}
	// 	// end pos_a
	// 	printf("\n");
	// 	printf("pos_a[%i] = %i ",i,pos[i].pos_a);
	// 	printf("pos_b[%i] = %i ",i,pos[i].pos_b);
	// 	i++;
	// 	top_b = top_b->next;
	// }
}