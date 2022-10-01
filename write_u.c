/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinigo <jinigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:38:48 by jinigo            #+#    #+#             */
/*   Updated: 2021/01/26 20:15:49 by jinigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	if_minus(t_pf *new, unsigned int nbr, int j)
{
	if (new->precision > j)
	{
		new->index_p = new->precision - j;
		if (new->width > new->precision)
			new->index_w = new->width - new->precision;
		while (new->index_p-- > 0)
			new->length += write(1, "0", 1);
		ft_putunbr_fd(nbr, 1, j);
		while (new->index_w-- > 0)
			new->length += write(1, " ", 1);
	}
	else if (new->width > j)
	{
		new->index_w = new->width - j;
		ft_putunbr_fd(nbr, 1, j);
		while (new->index_w-- > 0)
			new->length += write(1, " ", 1);
	}
	else
	{
		ft_putunbr_fd(nbr, 1, j);
	}
}

static void	if_else(t_pf *new, unsigned int nbr, int j)
{
	if (new->precision > j)
	{
		new->index_p = new->precision - j;
		if (new->width > new->precision)
			new->index_w = new->width - new->precision;
		while (new->index_w-- > 0)
			new->length += write(1, " ", 1);
		while (new->index_p-- > 0)
			new->length += write(1, "0", 1);
		ft_putunbr_fd(nbr, 1, j);
	}
	else if (new->width > j)
	{
		new->index_w = new->width - j;
		while (new->index_w-- > 0)
			if (new->zorro == 1 && new->precision == -1)
				new->length += write(1, "0", 1);
			else
				new->length += write(1, " ", 1);
		ft_putunbr_fd(nbr, 1, j);
	}
	else
	{
		ft_putunbr_fd(nbr, 1, j);
	}
}

static int	len_u(unsigned int a)
{
	int i;

	i = 0;
	if (a == 0)
		return (1);
	while (a != 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

int			write_u(t_pf *new, va_list ap)
{
	unsigned int	nbr;
	int				j;

	nbr = va_arg(ap, unsigned int);
	if (nbr == 0)
	{
		j = 1;
		if (new->precision == 0)
			j = 0;
	}
	else
		j = len_u(nbr);
	new->length += j;
	if (new->minus == '-')
		if_minus(new, nbr, j);
	else
		if_else(new, nbr, j);
	return (new->length);
}
