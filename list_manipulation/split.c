/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:10:19 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/15 16:12:22 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

size_t	ft_strlen(const char	*c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

int	wcount(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (n);
}

static int	spliting_problem(char **result, int n)
{
	if (!result[n])
	{
		while (n >= 0)
			free (result[n--]);
		free (result);
		return (1);
	}
	return (0);
}

static char	**str_to_split(char **result, char const *str, char c)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	j = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		j = i;
		while (str[j] && str[j] != c)
			j++;
		if (i < j)
		{
			result[word] = (char *)malloc((j - i + 1) * sizeof(char));
			if (spliting_problem(result, word))
				return (0);
			ft_strlcpy(result[word++], str + i, j - i + 1);
		}
		i = j;
	}
	result[word] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**split_str;

	if (!s)
		return (0);
	split_str = NULL;
	split_str = (char **) malloc((wcount(s, c) + 1) * sizeof(char *));
	if (!split_str)
		return (0);
	return (str_to_split(split_str, s, c));
}
