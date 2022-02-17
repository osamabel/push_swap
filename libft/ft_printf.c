/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:03:16 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/16 17:10:51 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

int	put_address(unsigned long nbr, char	*base)
{
	if (nbr >= 0 && nbr < 16)
		return (put_char(base[nbr]));
	else
		return (put_address(nbr / 16, base) + put_address(nbr % 16, base));
}

void	check_char(va_list list, char c, int *len, int *i)
{
	if (c == 'c')
		*len += put_char(va_arg(list, int));
	else if (c == 'd' || c == 'i')
		*len += put_number(va_arg(list, int));
	else if (c == 'u')
		*len += put_number_u(va_arg(list, unsigned int));
	else if (c == 's')
		*len += put_string(va_arg(list, char *));
	else if (c == 'x')
		*len += putnbr_base(va_arg(list, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		*len += putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
	{
		*len += put_string("0x");
		*len += put_address(va_arg(list, unsigned long), "0123456789abcdef");
	}
	else if (c == '%')
		*len += put_char('%');
	else
		(*i)--;
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			check_char(list, str[i], &len, &i);
		}
		else
			len += put_char(str[i]);
		i++;
	}
	va_end(list);
	return (len);
}
