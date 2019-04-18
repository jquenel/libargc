#include <stdlib.h>
#include "libargc.h"

t_arg		*ft_argnew(char flag, t_argtype type, char *content)
{
	t_arg	*argnew;

	if (!(argnew = (t_arg*)malloc(sizeof(t_arg))))
		return (NULL);
	argnew->flag = 0;
	if (flag != 0 && (flag < 'a' || flag > 'z'))
		return (NULL);
	if (flag != 0)
		argnew->flag |= 1 << (flag - 'a');
	argnew->type = type;
	if (type == INT)
	{
		argnew->intcontent = ft_atoi(content);
		argnew->strcontent = NULL;
	}
	else
	{
		argnew->intcontent = 0;
		argnew->strcontent = content;
	}
	argnew->next = NULL;
	return (argnew);
}
