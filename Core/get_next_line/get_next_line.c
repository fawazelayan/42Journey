/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:15:39 by felayan           #+#    #+#             */
/*   Updated: 2024/12/27 20:51:15 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	copy(t_list *list, char *line)
{
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	while (list)
	{
		i = 0;
		while (list -> s[i])
		{
			if (list -> s[i] == '\n')
			{
				line[k++] = '\n';
				line[k] = 0;
				return ;
			}
			line[k++] = list -> s[i++];
		}
		list = list -> next;
	}
	line[k] = 0;
}
t_list	*cleaned_last(t_list *list)
{
	while (list -> s[i] !)
	{ 

void	clean(t_list **list)
{
	t_list	*last;
	t_list	*new;
	t_list	*temp;

	last = find_last(*list);
	if (!list)
		return ;
	new = malloc(sizeof(t_list));
	if(!new)
		return ;
	new = last;
	while (*list)
	{
		temp = *list -> next;
		free(*list);
		*list = tmp;
	}
	*list = new;
}

void	create_list(t_list **list)
{
	size_t	chars_read;
	char	*buf;

	chars_read = 0;
	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (!chars_read)
		{
			free(buf);
			return ;
		}
		buf[chars_read] = 0;
		append(list, buf);
	}
}
char	*get_next_line(int fd)
{
	static t_list	*list;
	char	*line;

	list = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	create_list(&list);
	line = join(list);
	return (line);
}
