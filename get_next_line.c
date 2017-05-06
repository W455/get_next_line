/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 18:14:58 by oukrifa           #+#    #+#             */
/*   Updated: 2017/05/06 23:20:50 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*ft_strjoinandfree(char *s1, char *s2)
{
	char			*str;

	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_memmove(str, s1, ft_strlen(s1));
	ft_strncat(str, s2, ft_strlen(s2));
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (str);
}

static t_gnl		ft_realloc(int const fd, t_gnl gnl)
{
	if (gnl.i == gnl.size)
	{
		gnl.i = 0;
		if (!gnl.buff)
			if (!(gnl.buff = (char*)malloc(sizeof(*gnl.buff) * BUFF_SIZE)))
				gnl.i = FAILURE;
		if ((gnl.size = read(fd, gnl.buff, BUFF_SIZE)) == FAILURE)
			gnl.i = FAILURE;
	}
	return (gnl);
}

static int			read_line(char **line, t_gnl gnl)
{
	int				i;
	char			*save;

	i = 0;
	if (!(save = ft_strnew(BUFF_SIZE)))
		return (FAILURE);
	while (gnl.i < gnl.size)
	{
		if (gnl.buff[gnl.i] == '\n')
		{
			*line = ft_strjoinandfree(*line, save);
			return (gnl.i);
		}
		save[i] = gnl.buff[gnl.i];
		++i;
		++gnl.i;
		if (gnl.i == gnl.size)
		{
			*line = ft_strjoinandfree(*line, save);
			return (gnl.i);
		}
	}
	return (gnl.i);
}

int					get_next_line(int const fd, char **line)
{
	static t_gnl	gnl[MAX_FD];

	if (!line || fd < 0)
		return (FAILURE);
	gnl[fd] = ft_realloc(fd, gnl[fd]);
	if (gnl[fd].i == FAILURE || !(*line = ft_strnew(0)))
		return (FAILURE);
	while (gnl[fd].size)
	{
		if (gnl[fd].buff[gnl[fd].i] == '\n')
		{
			++gnl[fd].i;
			return (SUCCESS);
		}
		gnl[fd].i = read_line(line, gnl[fd]);
		gnl[fd] = ft_realloc(fd, gnl[fd]);
		if (gnl[fd].i == -1)
			return (FAILURE);
	}
	if (**line)
		return (SUCCESS);
	return (EOFF);
}
