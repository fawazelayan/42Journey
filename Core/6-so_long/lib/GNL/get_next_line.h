/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:41 by felayan           #+#    #+#             */
/*   Updated: 2025/02/19 14:47:44 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(const char *s1, const char *s2);
char	*ft_strdup_gnl(const char *s);
char	*ft_strchr_gnl(const char *s, int c);
int		ft_strlen_gnl(const char *s);
int		lentonew(const char *s);

#endif
//