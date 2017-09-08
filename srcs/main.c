/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <kialvare@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 11:47:35 by kialvare          #+#    #+#             */
/*   Updated: 2017/07/07 18:28:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	/*unsigned int i;
	int d;
	char *str;

	i = 4294967100;
	d = 42;
	str = "hello";
	ft_printf("ft_printf: %%|\n");
	printf("rl_printf: %%|\n");
	printf("\n");
	ft_printf("ft_printf: %c|\n", 'a');
	printf("rl_printf: %c|\n", 'a');
	printf("\n");
	ft_printf("ft_printf: %d|\n", d);
	printf("rl_printf: %d|\n", d);
	ft_printf("ft_printf: %u|\n", i);
	printf("rl_printf: %u|\n", i);
	ft_printf("\n");
	ft_printf("ft_printf: %05d|\n", 123);
	printf("rl_printf: %05d|\n", 123);*/

	int i;

	i = 42;
	printf("Real: %c\n", 'a');
	ft_printf("Mine: %c\n", 'a');

	printf("Real: %10d\n", +42);
	ft_printf("Mine: %10d\n", +42);

	printf("Real: %4.2d\n", +42);
	ft_printf("Mine: %4.2d\n", +42);

	printf("Real: %10.5d\n", +42);
	ft_printf("Mine: %10.5d\n", +42);

	printf("Real: %5.10d\n", +42);
	ft_printf("Mine: %5.10d\n", +42);

	/*printf("Real: %#d\n", +42);
	ft_printf("Mine: %#d\n", +42);*/

	printf("Real(unsigned): %0u\n", +42);
	ft_printf("Mine(unsigned): %0u\n", +42);

	printf("Real: %+d\n", +42);
	ft_printf("Mine: %+d\n", +42);

	printf("Real: %-d\n", +42);
	ft_printf("Mine: %-d\n", +42);

	printf("Real: %+d\n", -42);
	ft_printf("Mine: %+d\n", -42);

	/*printf("Real: %0-d\n", -42);
	ft_printf("Mine: %0-d\n", -42);*/

	printf("Real: %08x\n", i);
	ft_printf("Mine: %08x\n", i);
	return (0);
}
