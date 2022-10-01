/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinigo <jinigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:25:50 by jinigo            #+#    #+#             */
/*   Updated: 2021/01/27 14:54:04 by jinigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct	s_pf
{
	char		minus;
	int			zorro;
	int			width;
	int			precision;
	char		type;
	int			pref;
	int			index_w;
	int			index_p;
	int			length;
}				t_pf;

int				ft_printf(const char *s, ...);
char			*parse(char *s, t_pf *new, va_list *ap);
void			splitter(t_pf *new, va_list ap);
char			*ft_strchr(const char *str, int c);
size_t			ft_strlen(const char *str);
int				ft_isdigit(int src);
int				write_c(t_pf *new, va_list ap);
int				write_s(t_pf *new, va_list ap);
int				write_di(t_pf *new, va_list ap);
void			minus_di(t_pf *new, int nbr, int j);
void			else_di(t_pf *new, int nbr, int j);
int				write_u(t_pf *new, va_list ap);
int				write_x(t_pf *new, va_list ap);
int				write_p(t_pf *new, va_list ap);
void			minus_p(t_pf *new, unsigned long nbr, int j);
void			else_p(t_pf *new, unsigned long nbr, int j);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd, int j);
void			ft_putunbr_fd(unsigned int n, int fd, int j);
void			ft_putnbrx_fd(unsigned int n, int fd, int flagx, int j);
void			ft_putnbrp_fd(unsigned long n, int fd, int j);

#endif
