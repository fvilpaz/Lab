/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvilas-p <fvilas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:37:49 by fvilas-p          #+#    #+#             */
/*   Updated: 2025/12/30 21:57:20 by fvilas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, int n)
{
	char	*str;
	int		i;

	str = malloc(n + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < n)
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		k;
	int		start;

	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res || !s)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		res[k++] = ft_strndup(&s[start], i - start);
	}
	res[k] = NULL;
	return (res);
}
