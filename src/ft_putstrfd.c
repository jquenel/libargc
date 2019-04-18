#include <unistd.h>
#include "libargc.h"

int		ft_putstrfd(char *str, int fd)
{
	size_t	l;

	l = ft_strlen(str);
	return (write(fd, str, l));
}
