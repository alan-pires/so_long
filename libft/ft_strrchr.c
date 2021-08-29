/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 08:36:55 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/01 19:47:08 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p_s;
	int		i;
	char	match;

	i = ft_strlen(s);
	p_s = (char *)s;
	match = (char)c;
	while (i > 0)
	{
		if (p_s[i] == match)
			return (p_s + i);
		i--;
	}
	if (p_s[i] == match)
		return (p_s);
	return (NULL);
}
