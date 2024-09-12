/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:05:02 by felayan           #+#    #+#             */
/*   Updated: 2024/08/03 23:33:03 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	long long int	nbr;
	char			*number_name;
}				t_list;

void						ft_putchar(char c);
char						*ft_strdup(char *src);
void						ft_putstr(char *str);
long long int				ft_atoi(char *str);
char						*get_number(int fd);
char						*get_number_name(int fd, char *character);
t_list						*create_list(char *file);

#endif
