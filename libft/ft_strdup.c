/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 08:36:09 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/21 11:51:51 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	i;

	i = -1;
	if (!s1)
		return (NULL);
	copy = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (s1[++i])
		copy[i] = s1[i];
	copy[i] = '\0';
	return (copy);
}
