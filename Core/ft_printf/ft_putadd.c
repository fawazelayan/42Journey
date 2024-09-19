/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 02:09:50 by felayan           #+#    #+#             */
/*   Updated: 2024/09/19 05:40:55 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	put_p(unsigned long p)
{
	int		count;

	count = put_s("0x");
	if (p == 0)
		count += put_s("nil");
	count += put_hex(p, 'x');
	return (count);
}
