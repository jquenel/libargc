#include "libargc.h"

t_arg		*ft_argpushf(t_arg *arglst, t_arg *argnew)
{
	argnew->next = arglst;
	return (argnew);
}
