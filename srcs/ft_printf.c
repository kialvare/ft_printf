/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <kialvare@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 11:49:47 by kialvare          #+#    #+#             */
/*   Updated: 2017/07/07 18:26:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <stdio.h>
#include <stdarg.h>

// [ 0 , 1 , 2 ] ?
//   ^
//   ^argp

int		ft_printf(const char *format, ...)
{
	const char *p;
	va_list argp;
	unsigned int u;
	int percent;
	int d;
	char *s;
	t_flags flag;

	va_start(argp, format);
	p = format;
	while (*p != '\0')
	{
		if (*p != '%')
			ft_putchar(*p);
		else
		{
			char next = *++p;
			if (next == 'c')
				print_char(argp);
			else if (next == 's')
			{
				s = va_arg(argp, char *);
				ft_putstr(s);
			}
			else if (next == 'd')
			{
				d = va_arg(argp, int);
				ft_putstr(ft_itoa(d));
			}
			else if (next == '%')
			{
				percent = va_arg(argp, int);
				ft_putchar('%');
			}
			else if (next == 'u')
			{
				u = va_arg(argp, unsigned int);
				s = ft_itoa(u);
				ft_putstr(s);
			}
			else if (next == '0')
			{
				flag.zero = *p++;
				d = va_arg(argp, int);
				printf("num: %s\n", ft_itoa(flag.zero));
			}
		}
		p++;
	}
	va_end(argp);
	return (0);
}

