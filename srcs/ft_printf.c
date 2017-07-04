/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <kialvare@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 11:49:47 by kialvare          #+#    #+#             */
/*   Updated: 2017/07/03 16:19:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*parse_args(char *str, va_list args, t_conv *conversion)
{
	(void)conversion;
	(void)args;
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
	return (str);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	char *str;
	t_conv conversion;

	conversion.flag_var = (t_flags*)malloc(sizeof(t_flags) * 1);
	conversion.count = 0;
	va_start(args, format);
	str = (char*)format;
	while(*str != '\0')
	{
		while (*str != '%')
		{
			conversion.count++;
			ft_putchar(*str);
			str++;
		}
		if (*str == '%')
			str++;
		if (*str != '\0')
			str = parse_args(str, args, &conversion);
	}
	va_end(args);
	return (0);
}
