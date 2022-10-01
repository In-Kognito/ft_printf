/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinigo <jinigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:03:40 by jinigo            #+#    #+#             */
/*   Updated: 2021/01/27 12:51:27 by jinigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	if_minus(t_pf *new, char *str, int j)
{
	if (new->precision >= 0)
	{
		if (new->precision < j)
		{
			new->length += write(1, str, new->precision);
			if (new->width > new->precision)
				while ((new->width-- - new->precision) > 0)
					new->length += write(1, " ", 1);
		}
		else
		{
			new->length += write(1, str, j);
			if (new->width > j)
				while ((new->width-- - j) > 0)
					new->length += write(1, " ", 1);
		}
	}
	else
	{
		new->length += write(1, str, j);
		if (new->width > j)
			while (new->width-- > j)
				new->length += write(1, " ", 1);
	}
}

static void	if_zorro(t_pf *new, char *str, int j)
{
	if (new->precision >= 0)
	{
		if (new->width > new->precision)
		{
			while (new->width-- > new->precision)
				new->length += write(1, "0", 1);
			new->length += write(1, str, new->precision);
		}
		else
			new->length += write(1, str, new->precision);
	}
	else if (new->width > j)
	{
		while (new->width-- > j)
			new->length += write(1, "0", 1);
		new->length += write(1, str, j);
	}
	else
		new->length += write(1, str, j);
}

static void	if_else(t_pf *new, char *str, int j)
{
	if (new->precision < j)
	{
		if (new->width > new->precision)
		{
			while (new->width-- > new->precision)
				new->length += write(1, " ", 1);
			new->length += write(1, str, new->precision);
		}
		else
		{
			new->length += write(1, str, new->precision);
		}
	}
	else
	{
		if (new->width > j)
			while (new->width-- > j)
				new->length += write(1, " ", 1);
		new->length += write(1, str, j);
	}
}

int			write_s(t_pf *new, va_list ap)
{
	char	*str;
	int		j;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	j = ft_strlen(str);
	if (new->minus == '-')
		if_minus(new, str, j);
	else
	{
		if (new->zorro == 1)
			if_zorro(new, str, j);
		else if (new->precision >= 0)
			if_else(new, str, j);
		else if (new->width > j)
		{
			while (new->width-- > j)
				new->length += write(1, " ", 1);
			new->length += write(1, str, j);
		}
		else
			new->length += write(1, str, j);
	}
	return (new->width + new->precision + j);
}
