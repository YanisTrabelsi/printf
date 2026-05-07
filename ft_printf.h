/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 04:02:35 by ytrabels          #+#    #+#             */
/*   Updated: 2026/05/07 10:59:39 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_convert_tohex(unsigned long n, char *base);
int	ft_putnbr(long n);
int	ft_putptr(void *ptr);

#endif
