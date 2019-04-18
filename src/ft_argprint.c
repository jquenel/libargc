#include "libargc.h"

static void	print_binint(int n, int fd)
{
	int		d;

	d = 31;
	while (d >= 0)
	{
		if (n & (1 << d))
			ft_putcharfd('1', fd);
		else
			ft_putcharfd('0', fd);
		d--;
	}
}

void		ft_argprint(t_arg *arglst, int fd)
{
	t_arg	*tmp;

	tmp = arglst;
	ft_putstrfd("----- START PRINT ARGLST -----\n\n", fd);
	while (tmp)
	{
		print_binint(tmp->flag, fd);
		ft_putcharfd('\n', fd);
		ft_putcharfd(tmp->type, fd);
		ft_putcharfd('\n', fd);
		ft_putnbrfd(tmp->intcontent, fd);
		ft_putcharfd('\n', fd);
		if (tmp->strcontent)
			ft_putstrfd((char *)(tmp->strcontent), fd);
		ft_putcharfd('\n', fd);
		ft_putcharfd('\n', fd);
		tmp = tmp->next;
	}
	ft_putstrfd("-----  END PRINT ARGLST  -----\n", fd);
}
