/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:50:22 by apires-d          #+#    #+#             */
/*   Updated: 2021/05/31 20:32:41 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (lst && new)
	{
		aux = *lst;
		if (aux == NULL)
			*lst = new;
		else
		{
			while (aux->next)
				aux = aux->next;
			aux->next = new;
		}
	}
}
