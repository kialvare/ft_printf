/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <kialvare@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 11:49:47 by kialvare          #+#    #+#             */
/*   Updated: 2017/07/02 16:05:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

/* Flags:
** s S - String
** p - pointer
** d D - decimal signed integer
** i - decimal signed integer
** o O - octal integer
** u U - unsigned integer
** x X - hex integer
** c C - character
** %% - percentage sign
** #0-+ and ' ' - some flags shit
** minimum field-width
** precision?
** hh0
** h
** l
** ll
** j
** z
*/

int		ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	va_end(args);
	return (0);
}
