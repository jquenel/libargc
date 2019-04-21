#ifndef ARGC_H
# define ARGC_H

# include <string.h>

typedef	char	t_argtype;

# define T_INT	'i'
# define T_STR	's'
# define T_NO	'n'

/*
**	t_arg
**	The goal of this utility is to return a chained list of those.
**
**	stores the given flag as its mask
**	doesn't reallocate the strcontent
**	the type tells how the value should be read
*/

typedef struct	s_arg
{
	int					flag;
	t_argtype			type;
	int					intcontent;
	char const			*strcontent;
	struct s_arg		*next;
}				t_arg;

/*
**	t_argparser
**	Stores the parsing rules.
**
**	the function should be the one to be called with the result of ap_parse
**	they should accept a t_arg list and a int containing active flags
*/

typedef int (*t_pfunc)(t_arg *, int);

typedef struct	s_argparser
{
	t_argtype			types[32];
	int					flags;
	t_pfunc				f;
	char				*key;
	struct s_argparser	*next;
}				t_argparser;

typedef struct	s_parsed
{
	t_arg				*args;
	int					flags;
	t_pfunc				f;
}				t_parsed;

t_arg			*ft_argnew(char flag, t_argtype type, char const *content);
t_arg			*ft_argpushb(t_arg *arglst, t_arg *argnew);
t_arg			*ft_argpushf(t_arg *arglst, t_arg *argnew);
void			ft_argdel(t_arg *arglst);
void			ft_argprint(t_arg *arglst, int fd);

int				ft_atoi(char const *s);
size_t			ft_strlen(char const *s);
char			*ft_strdup(char const *s);
int				ft_strcmp(char const *s1, char const *s2);
int				ft_putcharfd(char c, int fd);
int				ft_putstrfd(char *str, int fd);
void			ft_putnbrfd(int nb, int fd);

t_argparser		*ap_new(char *key, t_pfunc f);
t_argparser		*ap_pushb(t_argparser *aplst, t_argparser *apnew);
void			ap_del(t_argparser *aplst);
int				ap_addrule(t_argparser *aplst, char flag, t_argtype type);
t_parsed		*ap_parse(t_argparser *aplst, int argc, char const **argv);
void			ap_printfd(t_argparser *aplst, int fd);

t_parsed		*parsednew(t_arg *args, t_argparser *parser);
void			parseddel(t_parsed *parsed);

#endif
