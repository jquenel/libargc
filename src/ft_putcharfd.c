#include <unistd.h>
#include "libargc.h"

int		ft_putcharfd(char c, int fd)
{
	return (write(fd, &c, 1));
}
