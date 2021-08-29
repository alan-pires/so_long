/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:10:09 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/28 10:16:57 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_int_to_hex(int nbr)
{
	char			*hex_alg;
	unsigned int	num;
	unsigned int	len;

	hex_alg = ft_strdup("0123456789abcdef");
	len = ft_strlen(hex_alg);
	num = nbr;
	if (num >= len)
		ft_int_to_hex(num / len);
	ft_putchar_fd(hex_alg[num % len], 1);
}
