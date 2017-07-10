/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 15:44:11 by kialvare          #+#    #+#             */
/*   Updated: 2017/07/07 12:34:58 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** p = current position
*/

int print_char(va_list argp, char next)
{
	int c;
	int percent;

	if (next == 'c')
	{
		c = va_arg(argp, int);
		ft_putchar(c);
	}
	else if (next == '%')
	{
		percent = va_arg(argp, int);
		ft_putchar('%');
	}
	return (0);
}
