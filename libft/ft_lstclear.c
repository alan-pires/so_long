/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:19:13 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/01 15:58:41 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*element;

	if (*lst && del)
	{
		element = *lst;
		while (element)
		{
			aux = element->next;
			ft_lstdelone(element, del);
			element = aux;
		}
		*lst = NULL;
	}
}
