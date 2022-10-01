/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinigo <jinigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:16:39 by jinigo            #+#    #+#             */
/*   Updated: 2021/01/27 14:19:32 by jinigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	for_if_minus(t_pf *new, int nbr, int j)
{
	new->index_p = new->precision - j;
	if (new->width > new->precision)
		new->index_w = new->width - new->precision;
	while (new->index_p-- > 0)
		new->length += write(1, "0", 1);
	ft_putnbr_fd(nbr, 1, j);
	if (new->pref == 1)
		while (--new->index_w > 0)
			new->length += write(1, " ", 1);
	else
		while (new->index_w-- > 0)
			new->length += write(1, " ", 1);
}

void		minus_di(t_pf *new, int nbr, int j)
{
	if (new->pref == 1)
		new->length += write(1, "-", new->pref);
	if (new->precision > j)
		for_if_minus(new, nbr, j);
	else if (new->width > j)
	{
		new->index_w = new->width - j;
		if (new->pref == 1)
		{
			ft_putnbr_fd(nbr, 1, j);
			while (--new->index_w > 0)
				new->length += write(1, " ", 1);
		}
		else
		{
			ft_putnbr_fd(nbr, 1, j);
			while (new->index_w-- > 0)
				new->length += write(1, " ", 1);
		}
	}
	else
		ft_putnbr_fd(nbr, 1, j);
}
