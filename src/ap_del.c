/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:11:17 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:11:41 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libargc.h"

void	ap_del(t_argparser *parser)
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
