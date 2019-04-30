#include "libargc.h"

t_argparser		*ap_duplicate(t_argparser *parser, char *newkey, t_pfunc newf)
{
	t_argparser		*newp;
	int				i;

	if (!(newp = ap_new(newkey, newf)))
		return (NULL);
	i = 0;
	while (i < 32)
	{
		newp->types[i] = parser->types[i];
		i++;
	}
	return (newp);
}
