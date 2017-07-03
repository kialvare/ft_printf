/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <kialvare@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 13:29:50 by kialvare          #+#    #+#             */
/*   Updated: 2017/07/02 16:05:05 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>

typedef struct	s_flags
{
	char		hash;
	char		zero;
	char		minus;
	char		plus;
	char		space;
}				t_flags;

typedef struct s_something
{
	
}

int		ft_printf(const char *format, ...);
