#include <stdlib.h>
#include "libargc.h"

void	ft_argdel(t_arg *arglst)
{
	t_arg	*tmp;
	t_arg	*tofree;

	if (!arglst)
		return ;
	tmp = arglst;
	while (tmp)
	{
		tofree = tmp;
		tmp = tmp->next;
		free(tofree);
	}
}
