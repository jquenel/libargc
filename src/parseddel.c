/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseddel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:18:14 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:18:14 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libargc.h"

void		parseddel(t_parsed *parsed)
{
	ft_argdel(parsed->args);
	free(parsed);
}
