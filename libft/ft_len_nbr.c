/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:57:58 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/24 15:59:01 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
