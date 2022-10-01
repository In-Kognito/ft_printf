/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_minus_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinigo <jinigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:57:20 by jinigo            #+#    #+#             */
/*   Updated: 2021/01/27 14:12:58 by jinigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	for_if_minus(t_pf *new, unsigned long nbr, int j)
{
	new->index_p = new->precision - j;
	new->length += new->index_p;
	if (new->width > new->precision + new->pref)
	{
		new->index_w = new->width - new->precision - new->pref;
		new->length += new->index_w;
		write(1, "0x", new->pref);
		while (new->index_p-- > 0)
			write(1, "0", 1);
		ft_putnbrp_fd(nbr, 1, j);
		while ((new->index_w-- - new->pref) > 0)
			write(1, " ", 1);
	}
}

void		minus_p(t_pf *new, unsigned long nbr, int j)
{
	if (new->precision > j)
		for_if_minus(new, nbr, j);
	else if (new->width > j + new->pref)
	{
		new->index_w = new->width - j - new->pref;
		new->length += new->index_w;
		write(1, "0x", new->pref);
		ft_putnbrp_fd(nbr, 1, j);
		while (new->index_w-- > 0)
			write(1, " ", 1);
	}
	else
	{
		write(1, "0x", new->pref);
		ft_putnbrp_fd(nbr, 1, j);
	}
}
