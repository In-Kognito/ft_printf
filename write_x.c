/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinigo <jinigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:54:59 by jinigo            #+#    #+#             */
/*   Updated: 2021/01/27 12:09:19 by jinigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	if_minus(t_pf *new, unsigned int nbr, int j, int flagx)
{
	if (new->precision > j)
	{
		new->index_p = new->precision - j;
		if (new->width > new->precision)
			new->index_w = new->width - new->precision;
		while (new->index_p-- > 0)
			new->length += write(1, "0", 1);
		ft_putnbrx_fd(nbr, 1, flagx, j);
		while (new->index_w-- > 0)
			new->length += write(1, " ", 1);
	}
	else if (new->width > j)
	{
		new->index_w = new->width - j;
		ft_putnbrx_fd(nbr, 1, flagx, j);
		while (new->index_w-- > 0)
			new->length += write(1, " ", 1);
	}
	else
		ft_putnbrx_fd(nbr, 1, flagx, j);
}

static void	if_else(t_pf *new, unsigned int nbr, int j, int flagx)
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
		ft_putnbrx_fd(nbr, 1, flagx, j);
	}
	else if (new->width > j)
	{
		new->index_w = new->width - j;
		if (new->zorro == 1 && new->precision == -1)
			while (new->index_w-- > 0)
				new->length += write(1, "0", 1);
		else
			while (new->index_w-- > 0)
				new->length += write(1, " ", 1);
		ft_putnbrx_fd(nbr, 1, flagx, j);
	}
	else
		ft_putnbrx_fd(nbr, 1, flagx, j);
}

static int	len_x(unsigned int a)
{
	int i;

	i = 0;
	if (a == 0)
		return (1);
	while (a != 0)
	{
		a = a / 16;
		i++;
	}
	return (i);
}

int			write_x(t_pf *new, va_list ap)
{
	unsigned int	nbr;
	int				j;
	int				flagx;

	nbr = va_arg(ap, int);
	if (nbr == 0)
	{
		j = 1;
		if (new->precision == 0)
			j = 0;
	}
	else
		j = len_x(nbr);
	new->length += j;
	flagx = 0;
	if (new->type == 'x')
		flagx = 1;
	if (new->minus == '-')
		if_minus(new, nbr, j, flagx);
	else
		if_else(new, nbr, j, flagx);
	return (new->length);
}
