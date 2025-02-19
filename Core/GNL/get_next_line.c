/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:45:44 by felayan           #+#    #+#             */
/*   Updated: 2025/02/18 21:45:45 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	reading(int fd, char **rem, char *buf)
{
	char	*tmp;
	int		bytesread;

	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(fd, buf, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(*rem);
			*rem = NULL;
			return ;
		}
		if (bytesread == 0)
			return ;
		buf[bytesread] = 0;
		if (!*rem)
			*rem = ft_strdup("");
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

	if (!rem || !*rem)
		return ;
	new_pos = ft_strchr(*rem, '\n');
	if (new_pos)
	{
		tmp = ft_strdup(new_pos + 1);
		if (!tmp)
		{
			free(*rem);
			*rem = NULL;
			return ;
		}
		free(*rem);
		*rem = tmp;
	}
	else
	{
		free(*rem);
		*rem = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(remain);
		remain = NULL;
		return (NULL);
	}
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	reading(fd, &remain, buf);
	free(buf);
	buf = NULL;
	if (!remain || !*remain)
	{
		free(remain);
		remain = NULL;
		return (NULL);
	}
	line = extract(remain);
	set_next_line(&remain);
	return (line);
}
