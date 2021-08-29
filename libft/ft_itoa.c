/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 08:34:51 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/01 15:41:45 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_abs(int n)
{
	long	num;

	num = n;
	if (n < 0)
		return (num * -1);
	return (num);
}

int	ft_len_nbr(int n)
{
	int		len;
	long	num;

	len = 1;
	num = ft_abs(n);
	while (num >= 10)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		i;
	int		len;

	num = ft_abs(n);
	i = 1;
	len = ft_len_nbr(n);
	if (n < 0)
		len++;
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	while (i <= len)
	{
		if (str[len - i] != '-')
			str[len - i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	str[len] = '\0';
	return (str);
}
