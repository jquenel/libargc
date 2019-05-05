/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrfd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:16:37 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:16:38 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libargc.h"

void	ft_putnbrfd(int nb, int fd)
{
	if (nb == -2147483648)
		ft_putstrfd("-2147483648", fd);
	else
	{
		if (nb < 0)
		{
			ft_putcharfd('-', fd);
			nb *= -1;
		}
		if (nb >= 10)
			ft_putnbrfd(nb / 10, fd);
		ft_putcharfd(nb % 10 + '0', fd);
	}
}
