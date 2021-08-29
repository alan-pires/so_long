/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 08:36:07 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/21 11:52:37 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
