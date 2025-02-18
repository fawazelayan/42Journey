/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 21:05:40 by felayan           #+#    #+#             */
/*   Updated: 2024/12/27 20:23:41 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char	*s;
	s_list	*next;
}	t_list;


t_list	*find_last(t_list *list);
void	append(t_list **list, char *buf);
void	create_list(t_list **list);
void	clean(t_list **list)
size_t	len_newline(t_list *list);
size_t	found_newline(t_list *list);
char	*join(t_list *list);
char	*get_next_line(int fd);

#endif
