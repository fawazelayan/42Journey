/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:31:52 by felayan           #+#    #+#             */
/*   Updated: 2024/09/19 05:39:43 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *fmt, ...);
int	put_c(char c);
int	put_s(char *s);
int	put_dec(long n);
int	put_hex(unsigned long n, char c);
int	put_p(unsigned long p);

#endif
