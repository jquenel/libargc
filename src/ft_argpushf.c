/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argpushf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:13:55 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:13:56 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libargc.h"

t_arg		*ft_argpushf(t_arg *arglst, t_arg *argnew)
{
	if (!argnew)
		return (NULL);
	if (!arglst)
		return (argnew);
	argnew->next = arglst;
	return (argnew);
}
