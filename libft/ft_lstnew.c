/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:03:42 by apires-d          #+#    #+#             */
/*   Updated: 2021/05/31 20:35:28 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_e;

	new_e = (t_list *)malloc(sizeof(t_list));
	if (new_e == NULL)
		return (NULL);
	new_e->content = content;
	new_e->next = NULL;
	return (new_e);
}
