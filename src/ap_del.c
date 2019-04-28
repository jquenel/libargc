#include <stdlib.h>
#include "libargc.h"

#include <stdio.h>
void			ap_del(t_argparser *parser)
{
	t_argparser		*tofree;
	t_argparser		*tmp;

	if (!parser)
		return ;
	tmp = parser;
	while (tmp)
	{
		tofree = tmp;
		tmp = tmp->next;
		free(tofree->key);
		free(tofree);
	}
}
