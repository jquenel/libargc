/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_pushb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:13:07 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:13:16 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
