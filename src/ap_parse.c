#include "libargc.h"

static t_argparser	*find_parser(t_argparser *aplst, char const *key)
{
	while (aplst)
	{
		if (!(ft_strcmp(aplst->key, key)))
			return (aplst);
		aplst = aplst->next;
	}
	return (NULL);
}

static char			get_flag(char const *arg)
{
	char		flag;

	if (ft_strlen(arg) != 2)
		return (0);
	flag = arg[1];
	if (flag < 'a' || flag > 'z')
		return (0);
	return (flag);
}

static t_arg		*parse_arg(int *i, int argc, char const **argv,
								t_argparser *parser)
{
	static int	end_flags = 0;
	char		flag;
	t_arg		*arg;
	t_argtype	type;

	flag = 0;
	type = T_STR;
	if (!(argv[*i][0] == '-') || !ft_strcmp("--", argv[*i]))
		end_flags = 1;
	if (!ft_strcmp("--", argv[*i]))
		type = T_NO;
	if (end_flags == 0)
	{
		if (!(flag = get_flag(argv[*i])))
			return (NULL);
		if (!(type = parser->types[(int)(flag - 'a')]))
			return (NULL);
		if (type != T_NO)	
			if (++(*i) >= argc)
				return (NULL);
	}
	arg = ft_argnew(flag, type, argv[*i]);
	*i += 1;
	return (arg);
}

t_parsed			*ap_parse(t_argparser *aplst, int argc, char const **argv)
{
	int			i;
	t_arg		*args;
	t_arg		*argnew;
	t_argparser	*parser;

	if (argc < 2 || !argv[1] || !argv[1][0])
		return (NULL);
	parser = find_parser(aplst, argv[1]);
	if (!parser)
		return (NULL);
	i = 2;
	args = NULL;
	while (i < argc)
	{
		argnew = parse_arg(&i, argc, argv, parser);
		if (!argnew)
		{
			ft_argdel(args);
			return (NULL);
		}
		parser->flags |= argnew->flag;
		args = ft_argpushb(args, argnew);
	}
	return (parsednew(args, parser));
}
