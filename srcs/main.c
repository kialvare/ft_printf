/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <kialvare@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 11:47:35 by kialvare          #+#    #+#             */
/*   Updated: 2017/07/03 16:30:13 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int i;

	i = 42;
	ft_printf("This is %s value number %d that is coming up %d\n", i);
	return (0);
}
