/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:11:57 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:11:59 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
