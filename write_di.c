/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinigo <jinigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:22:07 by jinigo            #+#    #+#             */
/*   Updated: 2021/01/27 14:40:13 by jinigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_di(int a)
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

int			write_di(t_pf *new, va_list ap)
{
	int	nbr;
	int	j;
	int	twin;

	nbr = va_arg(ap, int);
	twin = nbr;
	j = 0;
	if (twin == 0)
	{
		j = 1;
		if (new->precision == 0)
			j = 0;
	}
	else
		j = len_di(nbr);
	new->length += j;
	if (nbr < 0)
		new->pref = 1;
	if (new->minus == '-')
		minus_di(new, nbr, j);
	else
		else_di(new, nbr, j);
	return (new->length);
}
