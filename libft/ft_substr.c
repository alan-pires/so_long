/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 08:36:59 by apires-d          #+#    #+#             */
/*   Updated: 2021/08/30 22:17:50 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
