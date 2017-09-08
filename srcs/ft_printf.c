/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <kialvare@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 11:49:47 by kialvare          #+#    #+#             */
/*   Updated: 2017/07/07 18:26:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

char	valid_char(char c)
{
	if (c == 'd' || c == 'D' || c == 'i')
		return (1);
	if (c == 'p')
		return (1);
	if (c == 'x' || c == 'X')
		return (1);
	if (c == 'o' || c == 'O')
		return (1);
	if (c == 's' || c == 'S')
		return (1);
	if (c == 'c' || c == 'C')
		return (1);
	return (0);
}

int		get_size(int n, int base)
{
	int	size;
	int	i;

	size = 0;
	i = 1;
	if (n < 0 && (size = 1))
		n = -n;
	while (i < n)
	{
		i *= base;
		size++;
	}
	return (size);
}

int		get_base(char c)
{
	if (c == 'x' || c == 'X')
		return (16);
	if (c == 'o')
		return (8);
	if (c == 'b')
		return (2);
	return (10);
}

int			get_param_size(t_print *print, void *param)
{
	int		size;
	int		base;

	size = 1;
	base = 0;
	if (print->c != 's' || print->c != 'c')
	{
		base = get_base(print->c);
		size = get_size(*(int *)param, base);
	}
	else if (print->c == 's')
		size = ft_strlen(*(char **)param);
	return (size);
}

int		ft_putnchar(char c, int n)
{
	int		i;

	i = -1;
	while (++i < n)
		ft_putchar(c);
	return (1);
}

int		get_print_size(t_print *print,  int size)
{
	if (print->width == 0 && print->precision == 0)
		return (size);
	if (print->width > 0 && print->precision == 0)
		return (print->width - size);
	if (print->width == 0 && print->precision > 0)
		return (print->width - size);
	if (print->width > print->precision)
		return (print->width);
	return (print->precision);
}

void		print_param(t_print *print, void *param)
{
	if (print->c == 'd' || print->c == 'i')
	{
		if (print->flag == '-' && *(int *)param < 0)
			ft_putnbr(-(*(int *)param));
		else
			ft_putnbr(*(int *)param);
	}
	else if (print->c == 'c')
		ft_putchar(*(char *)param);
	else if (print->c == 'x' || print->c == 'X')
		ft_puthexa(*(int *)param, print->c);
	else if (print->c == 's')
		ft_putstr(*(char **)param);
	else if (print->c == 'o')
		ft_putbase(*(int *)param, 8, "01234567");
}

void	print_zero(char c)
{
	ft_putchar('0');
	ft_putchar(c);
}

int		start_print(t_print *print, va_list ap)
{
	long int	param = 0;
	int	print_size;
	int	size;
	int	ret;

	param = va_arg(ap, int);
	size = get_param_size(print, &param);
	print_size = get_print_size(print, size);
	ret = print_size;
	if ((print->flag == '+' && param > 0) || (print->flag == '-' && param < 0))
		print_size--;
	if (print->flag == '-' && param < 0)
		ft_putchar('-');
	print_size -= (print->flag == '#') ? 2 : 0;
	print_size += (print->c == 's') ? 1 : 0;
	if (print->flag == ' ' || (print->width > print->precision))
		ft_putnchar(' ', print_size - print->precision);
	if (print->flag == '#' && (print->c == 'x' || print->c == 'X'))
		print_zero(print->c);
	if ((print->flag == '0' && !print->precision) || print->precision)
		ft_putnchar('0', print->precision - size);
	if (print->flag == '+' && param > 0)
		ft_putchar('+');
	print_param(print, &param);
	return (ret);
}

void	populate_struct(t_print *print, int *i, const char *format)
{
	if ((print->flag = check_flag(format[*i])) > 0)
		(*i)++;
	print->width = get_width(format, i);
	print->precision = get_precision(format, i);
	print->length = get_mods(format, i);
	print->c = format[*i];
	(*i)++;
}

int		ft_printf(const char *format, ...)
{
	int		i;
	t_print	*print;
	va_list		ap;
	int		ret;

	i = -1;
	ret = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			//printf("|Form: %s|", format);
			//printf("|i: %d|\n", i);
			i++;
			if (!(print = (t_print *)malloc(sizeof(*print))))
				return (0);
			populate_struct(print, &i, format);
			//printf("\nLALA  %c  LALA\n", print->c);
			if (valid_char(print->c))
				ret += start_print(print, ap);
			free(print);
			print = NULL;
		}
		ft_putchar(format[i]);
		ret++;
	}
	return (ret);
}

