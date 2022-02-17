/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:45:04 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/16 17:11:11 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		len;

	len = ft_strlen(s1);
	p = (char *)malloc((sizeof(char) * (len + 1)));
	if (!p)
		return (0);
	ft_strlcpy(p, s1, len + 1);
	return (p);
}
