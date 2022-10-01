/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrx_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinigo <jinigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:57:50 by jinigo            #+#    #+#             */
/*   Updated: 2021/01/26 07:12:12 by jinigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrx_fd(unsigned int n, int fd, int flagx, int j)
{
	unsigned int	nbr;

	if (j > 0)
	{
		nbr = 0;
		if (n >= 16)
			ft_putnbrx_fd(n / 16, fd, flagx, j);
		nbr = (n % 16 > 9) ? n % 16 + 55 + (flagx * 32) : n % 16 + 48;
		ft_putchar_fd((char)(nbr), fd);
	}
}
