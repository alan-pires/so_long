/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:25:08 by apires-d          #+#    #+#             */
/*   Updated: 2021/08/30 23:30:23 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **p)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
}

static int	ft_get_line(char **line, int r_bytes, char **content)
{
	int		i;
	char	*aux;

	i = 0;
	if (r_bytes < 0)
		return (-1);
	else if ((*content)[0] == '\0' && r_bytes == 0)
	{
		*line = ft_strdup("");
		ft_free(content);
		return (0);
	}
	while ((*content)[i] != '\0' && (*content)[i] != '\n')
		i++;
	*line = ft_substr(*content, 0, i);
	if ((*content)[i] == '\n')
	{
		aux = ft_strdup(*content + i + 1);
		free(*content);
		*content = aux;
		return (1);
	}
	ft_free(content);
	return (0);
}

static int	ft_init_content(char **content)
{
	if (!(*content))
	{
		*content = ft_strdup("");
		if (!(*content))
			return (-1);
	}
	return (0);
}

static ssize_t	ft_bytes_read(int *fd, char *buff, ssize_t *r)
{
	*r = read(*fd, buff, BUFFER_SIZE);
	return (*r);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	char		*aux;
	static char	*content;
	ssize_t		r_bytes;

	r_bytes = 0;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (ft_init_content(&content) != 0)
		return (-1);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (-1);
	while (ft_bytes_read(&fd, buff, &r_bytes) > 0)
	{
		buff[r_bytes] = '\0';
		aux = ft_strjoin(content, buff);
		ft_free(&content);
		content = aux;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (ft_get_line(line, r_bytes, &content));
}
