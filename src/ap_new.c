/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:12:49 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:12:50 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libargc.h"

t_argparser		*ap_new(char *key, t_pfunc f)
{
	t_argparser	*parser;
	size_t		i;

	if (!(parser = (t_argparser*)malloc(sizeof(t_argparser))))
		return (NULL);
	if (!(parser->key = ft_strdup(key)))
	{
		free(parser);
		return (NULL);
	}
	i = 0;
	while (i < 32)
	{
		parser->types[i] = 0;
		i++;
	}
	parser->f = f;
	parser->flags = 0;
	parser->next = NULL;
	return (parser);
}
