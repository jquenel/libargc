/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_addrule.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:12:30 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:12:32 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libargc.h"

int		ap_addrule(t_argparser *parser, char flag, t_argtype type)
{
	int		f;

	if (flag > 'z' || flag < 'a')
	{
		ft_putstrfd("Invalid parser flag", 2);
		return (0);
	}
	f = (int)(flag - 'a');
	if (parser->types[f])
	{
		ft_putstrfd("Multiple parser rule for same flag : ", 2);
		ft_putcharfd(flag, 2);
		ft_putcharfd('\n', 2);
		return (0);
	}
	parser->types[f] = type;
	return (f);
}
