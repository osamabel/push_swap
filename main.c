/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:09:05 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/09 16:26:33 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

void display(t_list *top)
{
    if (top)
    {
        while (top)
        {
            printf ("%i ",top->content);
            top = top->next;
        }
    }
    else
        printf ("\nN U L L\n");
    printf ("\n");
}

void display_node(t_list *top)
{
    if (top)
        printf ("%i ",top->content);
    else
        printf ("\nN U L L\n");
    printf ("\n");
}

int all_done(t_list *top)
{
    while (top->next && top->content < top->next->content)
        top = top->next;
    if (top->next)
        return 0;
    return 1;
}

t_list *get_node_by_value(t_list *top, int position)
{
	int	i;

	i = 0;
	while (top && i < position)
	{
		top = top->next;
		i++;
	}
	if (top)
		return (top);
	return (0);
}



int	max_of_arr(int *list ,int size,int last_max)
{
	int i;
	int j;
	int m;

	i = 1;
	j = 0;
	m = list[0];
	while (i < size)
	{
		if (m <= list[i] && list[i] < last_max)
		{
			m = list[i];
			j = i;
		}
		i++;
	}
	return j;
}




// int main(int argc, char *argv[])
int main(void)
{
	t_list *top_a;
    t_list *top_b;
	int i;
	int *list_r;

	i = 0;
    top_a = NULL;
    top_b = NULL;
	// while (i < argc)
    // {
    //     ft_lstadd_back(&top_a,ft_lstnew(ft_atoi(argv[i])));
    //     i++;
    // }
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

	i = 0;
	list_r = largest_increasing_sequence(top_a);
	separet_lis(&top_a, &top_b, list_r);
	// display(top_a);
	// display(top_b);

	// while (i <= list_r[0])
	// {
	// 	printf("%i ",list_r[i]);
	// 	i++;
	// }
	ft_lstadd_back(&top_b,ft_lstnew(10));
	ft_lstadd_back(&top_b,ft_lstnew(10));
	ft_lstadd_back(&top_b,ft_lstnew(10));
	ft_lstadd_back(&top_b,ft_lstnew(7));
	ft_lstadd_back(&top_b,ft_lstnew(7));
	ft_lstadd_back(&top_b,ft_lstnew(8));
	ft_lstadd_back(&top_b,ft_lstnew(9));
	display(top_b);
	find_position(top_a, top_b);
	// display(top_b);
	// ft_quick_sort(&top_a,&top_b,0, ft_lstsize(top_a) - 1);
	// top_b = get_mid_point(top_a, 0, ft_lstsize(top_a) - 1);
	// printf("size = %i\n", ft_lstsize(top_a));
	// printf("mid = %i\n", top_b->content);

	// display(top_a);
	return 0;
}