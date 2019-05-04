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
	int					intcnt;
	char const			*strcnt;
	struct s_arg		*next;
}				t_arg;

# define FLAG_A		(1 << 0)
# define FLAG_B		(1 << 1)
# define FLAG_C		(1 << 2)
# define FLAG_D		(1 << 3)
# define FLAG_E		(1 << 4)
# define FLAG_F		(1 << 5)
# define FLAG_G		(1 << 6)
# define FLAG_H		(1 << 7)
# define FLAG_I		(1 << 8)
# define FLAG_J		(1 << 9)
# define FLAG_K		(1 << 10)
# define FLAG_L		(1 << 11)
# define FLAG_M		(1 << 12)
# define FLAG_N		(1 << 13)
# define FLAG_O		(1 << 14)
# define FLAG_P		(1 << 15)
# define FLAG_Q		(1 << 16)
# define FLAG_R		(1 << 17)
# define FLAG_S		(1 << 18)
# define FLAG_T		(1 << 19)
# define FLAG_U		(1 << 20)
# define FLAG_V		(1 << 21)
# define FLAG_W		(1 << 22)
# define FLAG_X		(1 << 23)
# define FLAG_Y		(1 << 24)
# define FLAG_Z		(1 << 25)
# define FLAG_26	(1 << 26)
# define FLAG_27	(1 << 27)
# define FLAG_28	(1 << 28)
# define FLAG_29	(1 << 29)
# define FLAG_30	(1 << 30)
# define FLAG_31	(1 << 31)

/*
**	t_argparser
**	Stores the parsing rules.
**
**	the function should be the one to be called with the result of ap_parse
**	they should accept a t_arg list and a int containing active flags
**  f is the function that should be called with the parsed args and flags
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
t_argparser		*ap_duplicate(t_argparser *parser, char *newkey, t_pfunc newf);
t_argparser		*ap_pushb(t_argparser *aplst, t_argparser *apnew);
void			ap_del(t_argparser *aplst);
int				ap_addrule(t_argparser *aplst, char flag, t_argtype type);
t_parsed		*ap_parse(t_argparser *aplst, int argc, char const **argv);
void			ap_printfd(t_argparser *aplst, int fd);

t_parsed		*parsednew(t_arg *args, t_argparser *parser);
void			parseddel(t_parsed *parsed);

#endif
