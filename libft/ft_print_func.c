/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:59:50 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/16 16:59:16 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

int	put_string(char	*str)
{
	int	i;

	if (str)
	{
		i = 0;
		while (str[i])
			i++;
		write(1, str, i);
		return (i);
	}
	else
		write(1, "(null)", 6);
	return (6);
}

int	put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	put_number(int n)
{
	if (n == -2147483648)
		return (put_string("-2147483648"));
	if (n < 0)
		return (put_char('-') + put_number(-n));
	else if (n > 9)
		return (put_number(n / 10) + put_number(n % 10));
	else
		return (put_char(n + '0'));
}

int	put_number_u(unsigned int n)
{
	if (n > 9)
		return (put_number(n / 10) + put_number(n % 10));
	else
		return (put_char(n + '0'));
}

int	putnbr_base(unsigned int nbr, char	*base)
{
	if (nbr >= 0 && nbr < 16)
		return (put_char(base[nbr]));
	else if (nbr < 0)
		return (put_char('-') + putnbr_base(-nbr, base));
	else
		return (putnbr_base(nbr / 16, base) + putnbr_base(nbr % 16, base));
}
