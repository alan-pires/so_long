/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 08:36:57 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/02 13:48:46 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !set)
		return (NULL);
	k = 0;
	i = 0;
	while (s1[i] && ft_isset(s1[i], set) == 1)
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_isset(s1[j - 1], set) == 1)
		j--;
	str = (char *)malloc(sizeof(*s1) * (j - i + 1));
	if (str == NULL)
		return (NULL);
	while (i < j)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}
