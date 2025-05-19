/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:02 by felayan           #+#    #+#             */
/*   Updated: 2025/02/19 14:50:54 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		*rem = ft_strdup_gnl("");
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
		*rem = ft_strjoin_gnl(tmp, buf);
		free (tmp);
		if (ft_strchr_gnl(buf, '\n'))
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

	new_pos = ft_strchr_gnl(*rem, '\n');
	if (new_pos)
	{
		tmp = ft_strdup_gnl(new_pos + 1);
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
	static char	*remain;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (freeing1(&remain));
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	reading(fd, &remain, buf);
	free(buf);
	buf = NULL;
	if (!remain || !*remain)
		return (freeing1(&remain));
	line = extract(remain);
	if (!line)
		return (freeing1(&remain));
	set_next_line(&remain);
	return (line);
}
//