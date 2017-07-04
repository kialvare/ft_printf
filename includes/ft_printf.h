/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <kialvare@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 13:29:50 by kialvare          #+#    #+#             */
/*   Updated: 2017/07/03 15:25:49 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

typedef struct	s_flags
{
	char		hash;
	char		zero;
	char		minus;
	char		plus;
	char		space;
}				t_flags;

typedef struct	s_conv
{
	t_flags		*flag_var;
	int			count;
}				t_conv;

int		ft_printf(const char *format, ...);
