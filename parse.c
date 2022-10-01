/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinigo <jinigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:42:07 by jinigo            #+#    #+#             */
/*   Updated: 2021/01/26 04:03:19 by jinigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*parse_precision(char *s, t_pf *new, va_list *ap)
{
	s++;
	new->precision = 0;
	if (*s == '*')
	{
		if ((new->precision = va_arg(*ap, int)) < 0)
			new->precision = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		new->precision = new->precision * 10 + *s - '0';
		s++;
	}
	return (s);
}

static char	*parse_width(char *s, t_pf *new, va_list *ap)
{
	if (*s == '*')
	{
		if ((new->width = va_arg(*ap, int)) < 0)
		{
			new->minus = '-';
			new->width = -new->width;
		}
		s++;
	}
	else
	{
		while (ft_isdigit(*s))
		{
			new->width = new->width * 10 + *s - '0';
			s++;
		}
	}
	return (s);
}

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
}

char		*parse(char *s, t_pf *new, va_list *ap)
{
	init_struct(new);
	s++;
	while (*s == '-' || *s == '0')
	{
		if (*s == '-')
			new->minus = '-';
		if (*s == '0')
			if (new->minus != '-')
				new->zorro = 1;
		s++;
	}
	if (*s == '*' || ft_isdigit(*s))
		s = parse_width(s, new, ap);
	if (*s == '.')
		s = parse_precision(s, new, ap);
	if (ft_strchr("cspdiuxX%", *s))
	{
		new->type = *s;
		splitter(new, *ap);
	}
	if (ft_strchr("cspdiuxX%", *s) == 0)
		return (0);
	return (s);
}
