/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsednew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:16:56 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:16:57 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libargc.h"

t_parsed		*parsednew(t_arg *args, t_argparser *parser)
{
	t_parsed	*parsed;

	if (!parser)
		return (NULL);
	if (!(parsed = (t_parsed *)malloc(sizeof(t_parsed))))
		return (NULL);
	parsed->args = args;
	parsed->flags = parser->flags;
	parsed->f = parser->f;
	return (parsed);
}
