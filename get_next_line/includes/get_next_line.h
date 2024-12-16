/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:47:21 by galambey          #+#    #+#             */
/*   Updated: 2023/05/15 11:52:36 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char	*get_next_line(int fd);
char	*get_next_line_multifd(int fd);
int		ft_present_char(char *buffer, char c);
char	*ft_new_line(char *line, char *buffer, int i);
char	*ft_read_fd(char *save, char *line, int fd);
size_t	ft_strlen_gnl(const char *s);
size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size);
char	*ft_strjoin_gnl(char const *s1, char const *s2, int i);
void	ft_bzero_gnl(void *s, size_t n);
void	ft_strcpy_gnl(char *dst, const char *src);
char	*ft_strdup(const char *s);

#endif