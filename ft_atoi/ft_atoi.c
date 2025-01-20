int	ft_atoi(const char *str)
{
	register long long	res;
	register const char	*s;
	int					sign;

	s = str;
	sign = 0;
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;

	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = 1;
		s++;
	}

	if (!*s || (*s == '0' && !*(s + 1)))
		return (0);

	res = 0;
	while (*s >= '0' && *s <= '9')
	{
		res = (res << 3) + (res << 1) + (*s++ & 0X0F);
		if (res < 0)
		{
			return sign ? 0 : -1;
		}
	}

	return (sign ? (int) -res : (int) res);
}
