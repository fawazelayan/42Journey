/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:08:35 by felayan           #+#    #+#             */
/*   Updated: 2024/08/03 23:26:10 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*get_number(int fd)
{
	int		i;
	char	charactar[1];
	char	*str;

	str = (char *) malloc(100);
	if (str == NULL)
		return (NULL);
	read(fd, charactar, 1);
	while (charactar[0] == '\n')
		read(fd, charactar, 1);
	i = 0;
	while (charactar[0] >= '0' && charactar[0] <= '9')
	{
		str[i] = charactar[0];
		read(fd, charactar, 1);
		i++;
	}
	return (str);
}

char	*get_number_name(int fd, char *charactar)
{
	int		i;
	char	*str;

	str = (char *) malloc(100);
	if (str == NULL)
	{
		ft_putstr("Error with allocation\n");
		return (NULL);
	}
	i = 0;
	while (charactar[0] != '\n')
	{
		str[i] = charactar[0];
		read(fd, charactar, 1);
		i++;
	}
	return (str);
}

int	error_check(int fd, t_list *list)
{
	if (list == NULL)
	{
		ft_putstr("Error with allocation\n");
		return (0);
	}
	if (fd == -1)
	{
		ft_putstr("Dict error\n");
		return (-1);
	}
	return (1);
}

void	reading(int fd, t_list *list, char *tmp, char *charactar)
{
	int	i;

	i = 0;
	while (i < 43)
	{
		list[i].nbr = ft_atoi(get_number(fd));
		read(fd, charactar, 1);
		while (charactar[0] == ' ')
			read(fd, charactar, 1);
		if (charactar[0] == ':')
			read(fd, charactar, 1);
		while (charactar[0] == ' ')
			read(fd, charactar, 1);
		tmp = get_number_name(fd, charactar);
		list[i].number_name = ft_strdup(tmp);
		free(tmp);
		i++;
	}
}

t_list	*create_list(char *file_name)
{
	int		fd;
	char	charactar[1];
	t_list	*list;
	char	*tmp;

	tmp = 0;
	fd = open(file_name, O_RDONLY);
	list = (t_list *)malloc(12 * 43);
	if (error_check(fd, list) == -1 || error_check(fd, list) == 0)
		return (NULL);
	reading(fd, list, tmp, charactar);
	if (close(fd) == -1)
	{
		ft_putstr("Dict error\n");
		return (NULL);
	}
	return (list);
}
