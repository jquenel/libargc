/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrfd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:16:08 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:16:09 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libargc.h"

int		ft_putstrfd(char *str, int fd)
{
	size_t	l;

	l = ft_strlen(str);
	return (write(fd, str, l));
}
