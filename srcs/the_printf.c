/*
** FT_PRINTF.C
*/

#include "ft_printf.h"
#include "libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

char			is_ok_c(char c)
{
	if (c == 'd' || c == 'i' || c == 'c')
		return (1);
	if (c == 'x' || c == 'X')
		return (1);
	if (c == 'o')
		return (1);
	if (c == 's')
		return (1);
	return (0);
}

void			fill_struct(t_printf *print, int *i, const char *format)
{
	if ((print->f = is_flag(format[*i])) > 0)
		(*i)++;
	print->f_w = check_width(format, i);
	print->prec = check_preci(format, i);
	print->l_m = check_modifier(format, i);
	print->c = format[*i];
	(*i)++;
}

int			ft_printf(const char *format, ...)
{
	int		i;
	t_printf	*print;
	va_list		ap;
	int		ret;

	i = -1;
	ret = 0;
	va_start(ap, NULL); 
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!(print = (t_printf *)malloc(sizeof(*print))))
				return (0);
			fill_struct(print, &i, format);
			printf("\nLALA  %c  LALA\n", print->c);
			if (is_ok_c(print->c))
				ret += print_stuff(print, ap);
			free(print);
			print = NULL;
		}
		ft_putchar(format[i]);
		ret++;
	}
	return (ret);
}

int			get_size_to_print(t_printf *print, void *param, int size)
{
	int		ret;
	int		base;

	base = get_base(print->c);
	if (print->f_w == 0 && print->prec == 0)
		return (size);
	if (print->f_w > 0 && print->prec == 0)
		return (print->f_w - size);
	if (print->f_w == 0 && print->prec > 0)
		return (print->f_w - size);
	if (print->f_w > print->prec)
		return (print->f_w);
	return (print->prec);
}

int			get_param_size(t_printf *print, void *param)
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

int			print_stuff(t_printf *print, va_list ap)
{
	long int	param = 0;
	int	size_to_print;
	int	size;
	int	ret;

	param = va_arg(ap, int);
	size = get_param_size(print, &param);
	size_to_print = get_size_to_print(print, &param, size);
	ret = size_to_print;
	if ((print->f == '+' && param > 0) || (print->f == '-' && param < 0))
		size_to_print--;
	if (print->f == '-' && param < 0)
		ft_putchar('-');
	size_to_print -= (print->f == '#') ? 2 : 0;
	size_to_print += (print->c == 's') ? 1 : 0;
	if (print->f == ' ' || (print->f_w > print->prec))
		ft_putnchar(' ', size_to_print - print->prec);
	if (print->f == '#' && (print->c == 'x' || print->c == 'X'))
		print_ox(print->c);
	if ((print->f == '0' && !print->prec) || print->prec)
		ft_putnchar('0', print->prec - size);
	if (print->f == '+' && param > 0)
		ft_putchar('+');
	print_param(print, &param);
	return (ret);
}

void		print_param(t_printf *print, void *param)
{
	if (print->c == 'd' || print->c == 'i')
	{
		if (print->f == '-' && *(int *)param < 0)
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

void		print_ox(char c)
{
	ft_putchar('0');
	ft_putchar(c);
}

/*
** GET.C
*/

int		check_width(const char *str, int *i)
{
	int ret;

	if (!str || str[*i] < '0' || str[*i] > '9')
		return (0);
	ret = 0;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
		ret = (ret * 10) + (str[(*i)++] - 48);
	return (ret);
}

int		check_preci(const char *str, int *i)
{
	int ret;

	if (!str || str[*i] != '.')
		return (0);
	(*i)++;
	ret = 0;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
		ret = (ret * 10) + (str[(*i)++] - 48);
	return (ret);
}

char		check_modifier(const char *str, int *i)
{
	if (str[*i] == 'h')
	{
		(*i)++;
		if (str[*i] == 'h')
			return (2);
		return (1);
	}
	if (str[*i] == 'l')
	{
		(*i)++;
		if (str[(*i)++] == 'l')
			return (4);
		return (3);
	}
	if (str[*i] == 'L')
		return (5);
	if (str[*i] == 'q')
		return (6);
	if (str[*i] == 'j')
		return (7);
	if (str[*i] == 'z')
		return (8);
	if (str[*i] == 'L')
		return (9);
	return (-1);

}

/*
** TOOLS.C
*/

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


