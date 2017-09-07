char	check_flag(char c)
{
	if (c == '#' || c == '+' || c == '-' || c == ' ' || c == '0')
		return (c);
	return (0);
}

int		get_width(const char *str, int *i)
{
	int w;

	if (!str || str[*i] < '0' || str[*i] > '9')
		return (0);
	w = 0;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
		w = (w * 10) + (str[(*i)++] - 48);
	return (w);
}

int		get_precision(const char *str, int *i)
{
	int p;

	if (!str || str[*i] != '.')
		return (0);
	(*i)++;
	p = 0;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
		p = (p * 10) + (str[(*i)++] - 48);
	return (p);
}

char	get_mods(const char *str, int *i)
{
	if (str[*i] == 'h')
	{
		(*i)++;
		if (str[*i] =='h')
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
