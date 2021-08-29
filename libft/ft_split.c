/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 08:36:04 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/14 11:35:53 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s, size_t n)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = malloc((n + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (s[i] && i < n)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static size_t	ft_count_split(char const *s, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			len++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	array;

	if (!s)
		return (NULL);
	i = 0;
	array = 0;
	tab = (char **)malloc((ft_count_split(s, c) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (i > j)
			tab[array++] = ft_strndup(s + j, i - j);
	}
	tab[array] = NULL;
	return (tab);
}
