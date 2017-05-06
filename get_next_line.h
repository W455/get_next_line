/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 01:57:34 by oukrifa           #+#    #+#             */
/*   Updated: 2017/05/06 23:28:30 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 43
# define MAX_FD 256
# define FAILURE -1
# define SUCCESS 1
# define EOFF 0
# include <fcntl.h>
# include <unistd.h>
# include "./libft/includes/libft.h"

typedef struct		s_gnl
{
	int				i;
	char			*buff;
	int				size;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
