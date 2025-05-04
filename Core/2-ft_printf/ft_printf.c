/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:57:53 by felayan           #+#    #+#             */
/*   Updated: 2024/11/30 17:44:11 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	fetch(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += put_dec(va_arg(ap, int));
	else if (c == 'x' || c == 'X')
		count += put_hex(va_arg(ap, unsigned int), c);
	else if (c == 'p')
		count += put_p(va_arg(ap, unsigned long));
	else if (c == 'u')
		count += put_dec(va_arg(ap, unsigned int));
	else if (c == 's')
		count += put_s(va_arg(ap, char *));
	else if (c == 'c')
		count += put_c(va_arg(ap, int));
	else
		count += put_c(c);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			count += fetch(format[++i], ap);
		else
			count += put_c(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
//