#include <stdio.h>	//for size_t

void	*ft_memcpy(void *dest, void *src, size_t l)
{
	register void  *d = dest;
	register void  *s = src;
	register size_t len = l;

	if (!dest || !src)
		return NULL;
	while (len && ((size_t) d % 8 != 0))
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

