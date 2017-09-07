#include "../libft/libft.h"
#include "../includes/ft_printf.h"

int		ft_putaddr(unsigned int n)
{
	ft_putstr("0x");
	return (ft_puthexa(n, 'x'));
}

int		ft_puthexa(unsigned int n, char flag)
{
	char	*tab;

	if (flag == 'x')
		tab = "0123456789abcdef";
	else
		tab = "0123456789ABCDEF";
	return (ft_putubase(n, 16, tab));
}

int		ft_putbase(int n, int base, char *tab)
{
	int	ret;

	ret = 0;
	if (n < 0)
	{
		ret = -ret;
		n = -n;
	}
	if (n < base)
	{
		ret = tab[n];
		ft_putchar(tab[n]);
	}
	else
	{
		ft_putbase(n / base, base, tab);
		ret += ft_putbase(n % base, base, tab);
	}
	return (ret);
}

int		ft_putubase(unsigned int n, unsigned int base, char *tab)
{
	if (n < base)
		ft_putchar(tab[n]);
	else
	{
		ft_putubase(n / base, base, tab);
		ft_putubase(n % base, base, tab);
	}
	return (1);
}
