#include "libargc.h"

t_arg		*ft_argpushb(t_arg *arglst, t_arg *argnew)
{
	t_arg	*tmp;

	if (!argnew)
		return (NULL);
	if (!arglst)
		return (argnew);
	tmp = arglst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = argnew;
	return (arglst);
}
