/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:20:35 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/19 15:46:35 by obelkhad         ###   ########.fr       */
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
	// i--;
	// if (!temp[i])
	// {
	// 	while (i >= 0)
	// 		free (temp[i--]);
	// 	free (temp);
	// }
	// temp = NULL;
	free_splited(temp, i);
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

int	verify_args(char **args, t_list **top_a, int counter)
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
				free_splited(args, counter);
				free_list(top_a);
				return (0);
			}
			j++;
		}
		ft_lstadd_back(top_a, ft_lstnew(arg));
	}
	free_splited(args, counter);
	return (check_doubles(top_a));
}

int	parsing_argument(int argc, char	*argv[], t_list **top_a)
{
	char	**args;
	int		i;
	int		j;
	int		counter;

	i = 1;
	j = 0;
	counter = 0;
	while (i < argc)
		counter += wcount(argv[i++], ' ');
	args = malloc(sizeof(char *) * (counter + 1));
	args[counter] = 0;
	i = 1;
	while (i < argc)
	{
		if (wcount(argv[i], ' ') == 1)
			args[j++] = ft_strtrim(argv[i], " ");
		else
			split_args(args, argv[i], &j);
		i++;
	}
	return (verify_args(args, top_a, counter));
}
