/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <kialvare@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 13:29:50 by kialvare          #+#    #+#             */
/*   Updated: 2017/07/07 17:55:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <inttypes.h>
#include <wchar.h>

typedef struct	s_flags
{
	char			hash;
	char			zero;
	char			minus;
	char			plus;
	char			space;
}				t_flags;

typedef struct	s_conv
{
	t_flags		*flag_var;
	int			count;
}				t_conv;

int		ft_printf(const char *format, ...);
int		print_char(va_list argp, char next);
int		print_nums(va_list argp, char next);
