#include "libargc.h"

static int	filler(t_arg *args, int flags)
{
	(void)args;
	return (flags);
}

int		main(int argc, char const **argv)
{
	t_argparser		*aplst;
	t_argparser		*parser;
	t_arg			*args;

	parser = ap_new("foo", filler);
	ap_addrule(parser, 'a', T_STR);
	ap_addrule(parser, 'b', T_INT);
	ap_addrule(parser, 'c', T_NO);
	
	aplst = parser;

	parser = ap_new("bar", filler);
	aplst = ap_pushb(aplst, parser);

	ap_printfd(aplst, 1);

	if (!(args = ap_parse(aplst, argc, argv)))
		ft_putstrfd("failed to parse\n", 1);
	else
	{
		ft_putstrfd("did not fail to parse\n", 1);
		ft_argprint(args, 1);
	}
	return (1);
}
