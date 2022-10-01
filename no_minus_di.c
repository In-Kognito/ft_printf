/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_minus_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinigo <jinigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:19:52 by jinigo            #+#    #+#             */
/*   Updated: 2021/01/27 14:48:19 by jinigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zorro(t_pf *new)
{
	if (new->zorro == 1 && new->precision == -1)
	{
		new->length += write(1, "-", new->pref);
		while (--new->index_w > 0)
			new->length += write(1, "0", 1);
	}
	else
	{
		while (--new->index_w > 0)
			new->length += write(1, " ", 1);
		new->length += write(1, "-", new->pref);
	}
}

static void	conf_prec(t_pf *new, int j)
{
	new->index_p = new->precision - j;
	if (new->width > new->precision)
		new->index_w = new->width - new->precision;
	if (new->pref == 1)
	{
		zorro(new);
	}
	else
	{
		while (new->index_w-- > 0)
		{
			if (new->zorro == 1 && new->precision == -1)
				new->length += write(1, "0", 1);
			else
				new->length += write(1, " ", 1);
		}
	}
	while (new->index_p-- > 0)
		new->length += write(1, "0", 1);
}

static void	zorro2(t_pf *new)
{
	if (new->zorro == 1 && new->precision == -1)
	{
		new->length += write(1, "-", new->pref);
		while (--new->index_w > 0)
			new->length += write(1, "0", 1);
	}
	else
	{
		while (--new->index_w > 0)
			new->length += write(1, " ", 1);
		new->length += write(1, "-", new->pref);
	}
}

static void	conf_wid(t_pf *new, int j)
{
	new->index_w = new->width - j;
	if (new->pref == 1)
	{
		zorro2(new);
	}
	else
	{
		while (new->index_w-- > 0)
		{
			if (new->zorro == 1 && new->precision == -1)
				new->length += write(1, "0", 1);
			else
				new->length += write(1, " ", 1);
		}
	}
}

void		else_di(t_pf *new, int nbr, int j)
{
	if (new->precision > j)
		conf_prec(new, j);
	else if (new->width > j)
	{
		conf_wid(new, j);
	}
	else
	{
		if (new->pref == 1)
			new->length += write(1, "-", new->pref);
	}
	if (nbr == 0 && new->precision == 0)
		new->length += write(1, "", 0);
	else
		ft_putnbr_fd(nbr, 1, j);
}
