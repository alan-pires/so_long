/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:25:16 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/14 20:42:49 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	p = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		p[len_s1++] = s2[i++];
	p[len_s1] = '\0';
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	i;

	i = -1;
	if (!s1)
		return (NULL);
	copy = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (s1[++i])
		copy[i] = s1[i];
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	match;

	i = 0;
	match = (char)c;
	while (s[i])
	{
		if (s[i] == match)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == match)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	si_len;

	if (!s)
		return (NULL);
	i = 0;
	si_len = ft_strlen(s);
	subs = malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	while ((i < len) && (start + i) < si_len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
