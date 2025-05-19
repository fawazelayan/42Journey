/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:43:05 by felayan           #+#    #+#             */
/*   Updated: 2025/02/19 15:43:06 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*freeing1(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

void	reading(int fd, char **rem, char *buf)
{
	char	*tmp;
	int		bytesread;

	if (!*rem)
		*rem = ft_strdup("");
	bytesread = 1;
	while (bytesread > 0 && *rem)
	{
		bytesread = read(fd, buf, BUFFER_SIZE);
		if (bytesread < 0)
		{
			freeing1(rem);
			return ;
		}
		if (bytesread == 0)
			return ;
		buf[bytesread] = 0;
		tmp = *rem;
		*rem = ft_strjoin(tmp, buf);
		free (tmp);
		if (ft_strchr(buf, '\n'))
			return ;
	}
}

char	*extract(const char *rem)
{
	int		len;
	int		i;
	char	*line;

	if (!rem)
		return (NULL);
	i = 0;
	len = lentonew(rem);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = rem[i];
		i++;
	}
	line[len] = 0;
	return (line);
}

void	set_next_line(char **rem)
{
	char	*new_pos;
	char	*tmp;

	new_pos = ft_strchr(*rem, '\n');
	if (new_pos)
	{
		tmp = ft_strdup(new_pos + 1);
		if (!tmp)
		{
			freeing1(rem);
			return ;
		}
		free(*rem);
		*rem = tmp;
	}
	else
		freeing1(rem);
}

char	*get_next_line(int fd)
{
	static char	*remain[1024];
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (freeing1(&remain[fd]));
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	reading(fd, &remain[fd], buf);
	free(buf);
	buf = NULL;
	if (!remain[fd] || !*remain[fd])
		return (freeing1(&remain[fd]));
	line = extract(remain[fd]);
	if (!line)
		return (freeing1(&remain[fd]));
	set_next_line(&remain[fd]);
	return (line);
}
//