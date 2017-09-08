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

#include "../libft/includes/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <inttypes.h>
#include <wchar.h>

typedef struct	s_print
{
	char		flag;
	int			width;
	int			precision;
	char		length;
	char		c;
}				t_print;

int		ft_printf(const char *format, ...);
int		print_char(va_list argp, char next);
int		print_nums(va_list argp, char next);

char	valid_char(char c);
int		start_print(t_print *print, va_list ap);
void	populate_struct(t_print *print, int *i, const char *format);

char	check_flag(char c);
int		get_width(const char *str, int *i);
int		get_precision(const char *str, int *i);
char	get_mods(const char *str, int *i);

int		ft_putaddr(unsigned int n);
int		ft_puthexa(unsigned int n, char flag);
int		ft_putbase(int n, int base, char *tab);
int		ft_putubase(unsigned int n, unsigned int base, char *tab);
