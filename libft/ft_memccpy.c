/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 08:34:54 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/02 19:41:39 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;
	size_t			i;

	i = 0;
	p_dest = dest;
	p_src = (unsigned char *)src;
	while (i < n)
	{
		((unsigned char *)p_dest)[i] = ((unsigned char *)p_src)[i];
		if (((unsigned char *)p_dest)[i] == (unsigned char)c)
			return ((void *)dest + i + 1);
		i++;
	}
	return (NULL);
}
