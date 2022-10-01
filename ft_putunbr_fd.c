/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinigo <jinigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 00:51:50 by jinigo            #+#    #+#             */
/*   Updated: 2021/01/26 07:09:21 by jinigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_fd(unsigned int n, int fd, int j)
{
	if (j > 0)
	{
		if (n >= 10)
			ft_putunbr_fd(n / 10, fd, j);
		ft_putchar_fd((char)(n % 10 + 48), fd);
	}
}
