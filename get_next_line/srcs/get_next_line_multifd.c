/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:35:18 by garance           #+#    #+#             */
/*   Updated: 2023/05/18 14:39:34 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_next_line_multifd(int fd)
{
	char			*line;
	static char		save[1024][BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > 1000000 || fd < 0)
		return (NULL);
	line = NULL;
	if (save[fd][0] && ft_present_char(save[fd], '\n') >= 0)
	{
		line = ft_strjoin_gnl(line, save[fd], ft_present_char(save[fd], '\n'));
		ft_strcpy_gnl(save[fd], save[fd] + ft_present_char(save[fd], '\n') + 1);
		return (line);
	}
	if (!save[fd][0])
	{
		ft_bzero_gnl(save[fd], BUFFER_SIZE + 1);
		return (ft_read_fd(save[fd], line, fd));
	}
	if (save[fd][0] && ft_present_char(save[fd], '\n') == -1)
	{
		line = ft_strjoin_gnl(line, save[fd], -1);
		if (!line)
			return (NULL);
		return (ft_read_fd(save[fd], line, fd));
	}
	return (NULL);
}
