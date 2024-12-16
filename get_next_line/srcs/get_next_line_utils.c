/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:47:39 by galambey          #+#    #+#             */
/*   Updated: 2023/05/16 13:03:52 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (dst == NULL && size == 0)
		return (ft_strlen_gnl(src) + size);
	len = ft_strlen_gnl(dst);
	if (len > size - 1 || size == 0)
		return (ft_strlen_gnl(src) + size);
	while (src[i] && len + i < size - 1)
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (ft_strlen_gnl(src) + len);
}

void	ft_strcpy_gnl(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (src)
	{	
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
	dst[i] = '\0';
	}
}

char	*ft_strjoin_gnl(char const *s1, char const *s2, int i)
{
	int			len;
	char		*s;

	if (!s1 && i == -1)
		len = ft_strlen_gnl(s2);
	else if (!s1)
		len = i + 1;
	else if (!s2)
		len = ft_strlen_gnl(s1);
	else if (i == -1)
		len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	else
		len = ft_strlen_gnl(s1) + i + 1;
	s = (char *)malloc(sizeof(char) *(len + 1));
	if (!s)
		return (NULL);
	s[0] = '\0';
	if (s1)
		ft_strlcat_gnl(s, s1, ft_strlen_gnl(s1) + 1);
	if (s2)
		ft_strlcat_gnl(s, s2, len + 1);
	return (s);
}

void	ft_bzero_gnl(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
