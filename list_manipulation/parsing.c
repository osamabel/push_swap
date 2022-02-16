/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:20:35 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/16 12:03:58 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void split_args(char **args, char *argv, int *j)
{
	char	**temp;
	int		i;

	i = 0;
	temp = ft_split(argv, ' ');
	while (temp[i])
	{
		args[*j] = ft_strtrim(temp[i], " ");
		(*j)++;
		i++;
	}
	free_splited(temp, i - 1);
}

int	check_doubles(t_list *top)
{
	t_list *head;

	while (top->next)
	{
		head = top->next;
		while (head && head->content != top->content)
			head = head->next;
		if (head)
			return 1;
		top = top->next;
	}
	return 0;
}

int	verify_args(char **args, t_list **top_a, int size)
{
	int	i;
	int	j;
	long arg;

	i = 0;
	while (args[i])
	{
		j = 0;
		arg = ft_atol(args[i]);
		while (args[i][j])
		{
			if (j == 0 && (args[i][j] == '+' || args[i][j] == '-'))
				j++;
			if (!ft_isdigit(args[i][j]) || arg > 2147483647 || arg < -2147483648)
			{
				free_splited(args, size - 1);
				free_list(top_a);
				return 0;
			}
			j++;
		}
		ft_lstadd_back(top_a,ft_lstnew(arg));
		i++;
	}
	free_splited(args, size - 1);
	if (check_doubles(*top_a))
	{
		free_list(top_a);
		return 0;
	}
	return 1;
}

int	parsing_argument(int argc, char	*argv[], t_list **top_a)
{
	char	**args;
	int		size;
	int		counter;
	int		i;
	int		j;

	i = 1;
	j = 0;
	size = 0;
	while (i < argc)
		size += wcount(argv[i++], ' ');
	counter = size;
	args = malloc(sizeof(char*) * (counter + 1));
	args[size] = 0;
	i = 1;
	while (i < argc)
	{
		counter = wcount(argv[i], ' ') == 1;
		if (counter == 1)
			args[j++] = ft_strtrim(argv[i], " ");
		else
			split_args(args, argv[i], &j);
		i++;
	}
	if (verify_args(args, top_a, size))
		return 1;
	return 0;
}

