/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 08:35:26 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/02 13:00:43 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*p_dest;
	char	*p_src;

	p_dest = (char *)dest;
	p_src = (char *)src;
	if (p_dest > p_src)
	{
		while (n)
		{
			n--;
			p_dest[n] = p_src[n];
		}
	}
	else if (p_dest < p_src)
		ft_memcpy(dest, src, n);
	return (dest);
}
