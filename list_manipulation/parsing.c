/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:20:35 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/15 16:26:56 by obelkhad         ###   ########.fr       */
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
		args[*j] = temp[i];
		(*j)++;
		i++;
	}
}

int	parsing_argument(int argc, char	*argv[])
{
	char	**args;
	int		counter;
	int		i;
	int		j;

	i = 1;
	j = 0;
	counter = 0;
	while (i < argc)
		counter += wcount(argv[i++], ' ');
	args = malloc(sizeof(char*) * (counter + 1));
	args[counter] = 0;
	i = 1;
	while (i < argc)
	{
		counter = wcount(argv[i], ' ') == 1;
		if (counter == 1)
		{
			args[j] = malloc(sizeof(char) * ft_strlen(argv[i]));
			args[j] = argv[i];
			j++;
		}
		else
			split_args(args, argv[i], &j);
		i++;
	}
	i = 0;
	while (args[i])
	{
		printf("> %s\n",args[i]);
		i++;
	}
	return 1;
}

