/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:15:36 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:15:37 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
