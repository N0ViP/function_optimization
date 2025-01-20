#include <stdio.h>	//for size_t

void	*ft_memset(void *str, int c, size_t n)
{
	register void			*s;
	register size_t			r;
	register size_t			l;
	register unsigned char	x;

	s = str;
	l = n;
	x = (unsigned char) c;
	r = 0x0101010101010101 * x;

	while (l && (l % 8 != 0))
	{
		*((char *) s++) = x;
		l--;
	}

	while (l >= sizeof(size_t))
	{
		*((size_t *) s) = r;
		l -= sizeof(size_t);
		s += sizeof(size_t);
	}

	while (l)
	{
		*((char *) s++) = x;
		l--;
	}

	return (str);
}
