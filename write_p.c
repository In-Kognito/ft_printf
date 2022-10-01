/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinigo <jinigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:19:43 by jinigo            #+#    #+#             */
/*   Updated: 2021/01/27 14:13:27 by jinigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_p(unsigned long a)
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

int			write_p(t_pf *new, va_list ap)
{
	unsigned long	nbr;
	int				j;

	nbr = va_arg(ap, unsigned long);
	if (nbr == 0)
	{
		j = 1;
		if (new->precision == 0)
			j = 0;
	}
	else
		j = len_p(nbr);
	new->pref = 2;
	new->length += new->pref + j;
	if (new->minus == '-')
	{
		minus_p(new, nbr, j);
	}
	else
	{
		else_p(new, nbr, j);
	}
	return (new->length);
}
