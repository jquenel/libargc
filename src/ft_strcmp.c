#include "libargc.h"
#include <string.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while ((((unsigned char)(s1[i])) && ((unsigned char)(s2[i]))) &&
			((unsigned char)(s1[i])) == ((unsigned char)(s2[i])))
		i++;
	return ((int)(((unsigned char)(s1[i])) - ((unsigned char)(s2[i]))));
}
