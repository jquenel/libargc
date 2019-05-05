/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:13:35 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:13:37 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libargc.h"

t_arg		*ft_argnew(char flag, t_argtype type, char const *content)
{
	t_arg	*argnew;

	if (!content)
		return (NULL);
	if (flag != 0 && (flag < 'a' || flag > 'z'))
		return (NULL);
	if (!(argnew = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	argnew->flag = 0;
	if (flag != 0)
		argnew->flag |= 1 << (flag - 'a');
	argnew->type = type;
	if (type == T_INT)
		argnew->intcnt = ft_atoi(content);
	else
		argnew->intcnt = 0;
	if (type == T_STR)
		argnew->strcnt = content;
	else
		argnew->strcnt = NULL;
	argnew->next = NULL;
	return (argnew);
}
