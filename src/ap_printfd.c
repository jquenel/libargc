#include "libargc.h"

void		print_types(t_argtype types[sizeof(int)], int fd)
{
	unsigned int	i;

	i = 0;
	while (i < 32)
	{
		if (types[i])
			ft_putcharfd((char)types[i], fd);
		else
			ft_putcharfd('0', fd);
		ft_putcharfd(' ', fd);
		i++;
	}
}

void		ap_printfd(t_argparser *aplst, int fd)
{
	t_argparser		*tmp;

	tmp = aplst;
	ft_putstrfd("----- START PRINT PARSER -----\n\n", fd);
	while (tmp)
	{
		print_types(tmp->types, fd);
		ft_putcharfd('\n', fd);
		ft_putstrfd(tmp->key, fd);
		ft_putcharfd('\n', fd);
		ft_putcharfd('\n', fd);
		tmp = tmp->next;
	}
	ft_putstrfd("-----  END PRINT PARSER  -----\n", fd);
}
