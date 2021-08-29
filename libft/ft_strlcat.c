/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 08:36:25 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/02 12:31:18 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	while (*dst && len < size)
	{
		dst++;
		len++;
	}
	while (*src && len + 1 < size)
	{
		*dst = *src;
		dst++;
		src++;
		len++;
	}
	if (len < size)
		*dst = '\0';
	while (*src)
	{
		src++;
		len++;
	}
	return (len);
}
