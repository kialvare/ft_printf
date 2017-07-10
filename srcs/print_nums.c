/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 15:25:22 by kialvare          #+#    #+#             */
/*   Updated: 2017/07/06 15:43:55 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int print_nums(va_list argp, char next)
{
	int d;
	unsigned int u;
	char *s;

	if (next == 'd')
	{
		d = va_arg(argp, int);
		ft_putstr(ft_itoa(d));
	}
	else if (next == 'u')
	{
		u = va_arg(argp, unsigned int);
		s = ft_itoa(u);
		ft_putstr(s);
	}

	return (0);
}
