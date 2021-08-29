/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 08:36:53 by apires-d          #+#    #+#             */
/*   Updated: 2021/05/31 20:46:44 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_aux;

	if (*needle == '\0')
		return ((char *)haystack);
	len_aux = ft_strlen(needle);
	while (*haystack && len-- >= len_aux)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, len_aux) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
