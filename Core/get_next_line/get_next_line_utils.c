/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 21:22:59 by felayan           #+#    #+#             */
/*   Updated: 2024/12/27 20:30:09 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

t_list	*find_last(t_list *list)
{
	while (list -> next)
		list = list -> next;
	return (list);
}

void	append(t_list **list, char *buf)
{
	t_list	*last;
	t_list	*new;
	
	last = find_last(*list);
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	if(!list)
		return ;
	if (!(*list))
		last = new;
	else
		last -> next = new;
	new -> s = buf;
	new -> next = NULL;
}

size_t	len_newline(t_list *list)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (list)
	{
		i = 0;
		while (list -> s[i])
		{
			if (list -> s[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list -> next;
	}
	return (len);
}

size_t	found_newline(t_list *list)
{
	size_t	i;

	i = 0;
	while (list)
	{
		i = 0;
		while (list -> s[i])
		{
			if (list -> s[i] == '\n')
				return (1);
			i++;
		}
		list = list -> next;
	}
	return (0);
}

char	*join(t_list *list)
{
	size_t	len;
	char	*line;

	len = len_newline(list);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	copy(list, line);
	return (line);
}
