/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argpushb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:17:57 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:17:58 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
