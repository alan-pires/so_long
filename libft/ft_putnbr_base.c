/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:36:07 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/14 11:36:49 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	show_number(char *base, int nbr, unsigned int str_len)
{
	unsigned int	num;

	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		num = nbr * -1;
	}
	else
		num = nbr;
	if (num >= str_len)
		show_number(base, num / str_len, str_len);
	ft_putchar_fd(base[num % str_len], 1);
}

static int	check_errors(char *base)
{
	int	i;
	int	j;

	if (!base)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + j;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	str_len;

	str_len = 2;
	str_len = check_errors(base);
	if (str_len)
		show_number(base, nbr, str_len);
}
