/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:10:19 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/16 08:25:56 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}


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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		p = malloc(sizeof(char));
		if (!p)
			return (0);
		*p = 0;
		return (p);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	ft_strlcpy(p, s + start, len + 1);
	p[len + 1] = '\0';
	return (p);
}
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
static int	ft_letter(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i] && c != set[i])
		i++;
	if (set[i] == c)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (ft_letter(set, s1[i]) && s1[i])
		i++;
	j = ft_strlen(s1) - 1;
	if (i == j + 1)
		return (ft_strdup(""));
	while (j > i && ft_letter(set, s1[j]))
		j--;
	return (ft_substr(s1, i, j - i + 1));
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

int	free_splited(char **result, int n)
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

char	**str_to_split(char **result, char const *str, char c)
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
			if (free_splited(result, word))
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
