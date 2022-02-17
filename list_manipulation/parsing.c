/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:20:35 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/17 11:48:06 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void	split_args(char **args, char *argv, int *j)
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

int	check_doubles(t_list **top)
{
	t_list	*head;
	t_list	*temp;

	temp = *top;
	while (temp->next)
	{
		head = temp->next;
		while (head && head->content != temp->content)
			head = head->next;
		if (head)
		{
			free_list(top);
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

int	verify_args(char **args, t_list **top_a, int size)
{
	int		i;
	int		j;
	long	arg;

	i = -1;
	while (args[++i])
	{
		j = 0;
		arg = ft_atol(args[i]);
		while (args[i][j])
		{
			if (j == 0 && (args[i][j] == '+' || args[i][j] == '-'))
				j++;
			if (ft_isdigit(args[i][j]) || arg > 2147483647 || arg < -2147483648)
			{
				free_splited(args, size - 1);
				free_list(top_a);
				return (0);
			}
			j++;
		}
		ft_lstadd_back(top_a, ft_lstnew(arg));
	}
	free_splited(args, size - 1);
	return (check_doubles(top_a));
}

int	parsing_argument(int argc, char	*argv[], t_list **top_a)
{
	char	**args;
	int		tab[4];

	tab[0] = 1;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	while (tab[0] < argc)
		tab[2] += wcount(argv[tab[0]++], ' ');
	args = malloc(sizeof(char *) * (tab[2] + 1));
	args[tab[2]] = 0;
	tab[0] = 1;
	while (tab[0] < argc)
	{
		tab[3] = wcount(argv[tab[0]], ' ') == 1;
		if (tab[3] == 1)
			args[tab[1]++] = ft_strtrim(argv[tab[0]], " ");
		else
			split_args(args, argv[tab[0]], tab + 1);
		tab[0]++;
	}
	if (verify_args(args, top_a, tab[2]))
		return (1);
	return (0);
}
