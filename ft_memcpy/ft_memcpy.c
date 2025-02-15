#include <stdio.h>	//for size_t

void	*ft_memcpy(void *dest, const void *src, size_t l)
{
	void		*d = dest;
	const void	*s = src;
	size_t		len = l;

	if (!dest || !src)
		return NULL;

	while (((size_t) d % 8 != 0) && len)
	{
		*((char *) d++) = *((char *) s++);
		len--;
	}

	while (len >= sizeof(size_t))
	{
		*((size_t *) d) = *((size_t *) s);
		d += sizeof(size_t);
		s += sizeof(size_t);
		len -= sizeof(size_t);
	}

	while (len)
	{
		*((char *) d++) = *((char *) s++);
		len--;
	}

	return (dest);
}
