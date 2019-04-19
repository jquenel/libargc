#include <stdlib.h>
#include "libargc.h"

t_parsed		*parsednew(t_arg *args, t_argparser *parser)
{
	t_parsed	*parsed;

	if (!args || !parser)
		return (NULL);
	if (!(parsed = (t_parsed *)malloc(sizeof(t_parsed))))
		return (NULL);
	parsed->args = args;
	parsed->flags = parser->flags;
	parsed->f = parser->f;
	return (parsed);
}
