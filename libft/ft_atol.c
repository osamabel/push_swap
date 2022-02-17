/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:03:10 by obelkhad          #+#    #+#             */
/*   Updated: 2021/11/16 11:55:55 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

int	ft_ispace(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v'
		|| c == '\f');
}

long	ft_atol(const char *str)
{
	int		i;
	int		minus;
	long	result;

	minus = 1;
	result = 0;
	i = 0;
	if (str[i] && ft_ispace(str[i]))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i++] == '-')
			minus = -minus;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (result * minus);
}
