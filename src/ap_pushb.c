#include "libargc.h"

t_argparser		*ap_pushb(t_argparser *aplst, t_argparser *apnew)
{
	t_argparser		*tmp;

	if (!apnew)
		return (NULL);
	if (!aplst)
		return (apnew);
	tmp = aplst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = apnew;
	return (aplst);
}
