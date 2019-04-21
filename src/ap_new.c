#include <stdlib.h>
#include "libargc.h"

t_argparser		*ap_new(char *key, t_pfunc f)
{
	t_argparser	*parser;
	size_t		i;

	if (!(parser = (t_argparser*)malloc(sizeof(t_argparser))))
		return (NULL);
	if (!(parser->key = ft_strdup(key)))
	{
		free(parser);
		return (NULL);
	}
	parser->key = key;
	i = 0;
	while (i < 32)
	{
		parser->types[i] = 0;
		i++;
	}
	parser->f = f;
	parser->flags = 0;
	parser->next = NULL;
	return (parser);
}
