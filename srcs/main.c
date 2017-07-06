/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <kialvare@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 11:47:35 by kialvare          #+#    #+#             */
/*   Updated: 2017/07/05 19:26:47 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	unsigned int i;
	int d;
	char *str;

	i = 4294967100;
	d = 42;
	str = "hello";
	printf("printf: This is %s the num: %u it's 5%%\n", str, i);
	ft_printf("ft_printf: This is %s the num: %u it's 5%%\n", str, i);
	printf("printf: This is the num: %05d", d);
	ft_printf("ft_printf: This is the num: %05d", d);
	return (0);
}
