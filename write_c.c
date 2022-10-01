/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinigo <jinigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:13:38 by jinigo            #+#    #+#             */
/*   Updated: 2021/01/27 12:04:50 by jinigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	if_minus(t_pf *new, char c)
{
	if (c == '\0')
		new->length += write(1, "", 1);
	else
		new->length += write(1, &c, 1);
	if (new->width > 1)
	{
		new->index_w = new->width;
		if (new->zorro == 1)
			while (--new->width > 0)
				new->length += write(1, "0", 1);
		else
			while (--new->width > 0)
				new->length += write(1, " ", 1);
	}
}

static void	if_else(t_pf *new, char c)
{
	if (new->width > 1)
	{
		new->index_w = new->width;
		while (--new->width > 0)
		{
			if (new->zorro == 1)
				new->length += write(1, "0", 1);
			else
				new->length += write(1, " ", 1);
		}
		if (c == '\0')
			new->length += write(1, "", 1);
		else
			new->length += write(1, &c, 1);
	}
	else
	{
		if (c == '\0')
			new->length += write(1, "", 1);
		else
			new->length += write(1, &c, 1);
	}
}

int			write_c(t_pf *new, va_list ap)
{
	char	c;

	if (new->type == '%')
		c = '%';
	else
		c = va_arg(ap, int);
	if (new->minus == '-')
		if_minus(new, c);
	else
	{
		if_else(new, c);
	}
	return (new->length);
}
