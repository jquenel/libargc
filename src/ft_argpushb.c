#include "libargc.h"

t_arg		*ft_argpushb(t_arg *arglst, t_arg *argnew)
{
	t_arg	*tmp;

	tmp = arglst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = argnew;
	return (arglst);
}
