/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrp_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinigo <jinigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:57:50 by jinigo            #+#    #+#             */
/*   Updated: 2021/01/26 17:25:04 by jinigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrp_fd(unsigned long n, int fd, int j)
{
	unsigned long	nbr;

	if (j > 0)
	{
		nbr = 0;
		if (n >= 16)
			ft_putnbrp_fd(n / 16, fd, j);
		nbr = (n % 16 > 9) ? n % 16 + 87 : n % 16 + 48;
		ft_putchar_fd((char)(nbr), fd);
	}
}
