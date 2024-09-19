/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 02:09:50 by felayan           #+#    #+#             */
/*   Updated: 2024/09/19 20:23:40 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	put_p(unsigned long p)
{
	int		count;

	if (p == 0)
		return (put_s("(nil)"));
	count = put_s("0x");
	count += put_hex(p, 'x');
	return (count);
}
