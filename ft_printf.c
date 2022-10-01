/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinigo <jinigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:35:44 by jinigo            #+#    #+#             */
/*   Updated: 2021/01/27 11:53:38 by jinigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_struct(t_pf *new)
{
	new->minus = 0;
	new->zorro = 0;
	new->width = 0;
	new->precision = -1;
	new->type = 0;
	new->pref = 0;
	new->index_w = 0;
	new->index_p = 0;
	new->length = 0;
}

void		splitter(t_pf *new, va_list ap)
{
	if (new->type == 'c' || new->type == '%')
		write_c(new, ap);
	if (new->type == 's')
		write_s(new, ap);
	if (new->type == 'd' || new->type == 'i')
		write_di(new, ap);
	if (new->type == 'u')
		write_u(new, ap);
	if (new->type == 'x' || new->type == 'X')
		write_x(new, ap);
	if (new->type == 'p')
		write_p(new, ap);
}

int			ft_printf(const char *s, ...)
{
	va_list	ap;
	t_pf	new;

	init_struct(&new);
	va_start(ap, s);
	while (*s)
	{
		if (*s != '%')
			new.length += write(1, s, 1);
		else
		{
			if ((s = parse((char *)s, &new, &ap)) == 0)
				return (-1);
		}
		s++;
	}
	va_end(ap);
	return (new.length);
}
