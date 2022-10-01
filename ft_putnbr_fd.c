/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinigo <jinigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:57:50 by jinigo            #+#    #+#             */
/*   Updated: 2021/01/26 21:45:38 by jinigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd, int j)
{
	unsigned int	nbr;

	if (j > 0)
	{
		if (n < 0)
			nbr = (unsigned int)(n * -1);
		else
			nbr = (unsigned int)n;
		if (nbr >= 10)
			ft_putnbr_fd(nbr / 10, fd, j);
		ft_putchar_fd((char)(nbr % 10 + 48), fd);
	}
}
