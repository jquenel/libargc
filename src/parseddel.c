#include <stdlib.h>
#include "libargc.h"

void		parseddel(t_parsed *parsed)
{
	ft_argdel(parsed->args);
	free(parsed);
}
