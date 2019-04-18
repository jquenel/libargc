#ifndef ARGC_H
# define ARGC_H

# include <string.h>

typedef			char	t_argtype;
# define INT	'i'
# define STR	's'


/*
**	t_arg
**	stores the given flag as its mask
**	doesn't reallocate the strcontent
**	the type tells how the value should be read
*/

typedef struct	s_arg
{
	int				flag;
	t_argtype		type;
	int				intcontent;
	char			*strcontent;
	struct s_arg	*next;
}				t_arg;

t_arg			*ft_argnew(char flag, t_argtype type, char *content);
t_arg			*ft_argpushb(t_arg *arglst, t_arg *argnew);
t_arg			*ft_argpushf(t_arg *arglst, t_arg *argnew);
void			ft_argdel(t_arg *arglst);

int				ft_atoi(char const *s);
int				ft_strlen(char const *s);

#endif
