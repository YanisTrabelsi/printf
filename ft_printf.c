/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels <ytrabels@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 01:46:52 by ytrabels          #+#    #+#             */
/*   Updated: 2026/05/07 11:02:30 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdarg.h>

static void	parser_episode2(char *fmt, va_list ap, int i, int *len);

static int	parser(char *fmt, va_list ap)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (fmt[i])
	{
		if (fmt[i] != '%')
			len += ft_putchar(fmt[i]);
		if (fmt[i] == '%')
		{
			++i;
			if (fmt[i] == 'c')
				len += ft_putchar(va_arg(ap, int));
			if (fmt[i] == 's')
				len += ft_putstr(va_arg(ap, char *));
			if (fmt[i] == 'p')
				len += ft_putptr(va_arg(ap, void *));
			parser_episode2(fmt, ap, i, &len);
		}
		++i;
	}
	return (len);
}

static void	parser_episode2(char *fmt, va_list ap, int i, int *len)
{
	if (fmt[i] == 'd' || fmt[i] == 'i')
		*len += ft_putnbr(va_arg(ap, int));
	if (fmt[i] == 'u')
		*len += ft_putnbr(va_arg(ap, long));
	if (fmt[i] == 'x')
		*len += ft_convert_tohex(va_arg(ap, long), "0123456789abcdef");
	if (fmt[i] == 'X')
		*len += ft_convert_tohex(va_arg(ap, long), "0123456789ABCDEF");
	if (fmt[i] == '%')
		*len += ft_putchar('%');
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, fmt);
	len = parser((char *)fmt, ap);
	va_end(ap);
	return (len);
}
/*
int	main(void)
{
	int	i;

	i = 10;
	ft_printf("char (h): %c\nstr (Hello Louka): %s\n", 'h', "Hello Louka");
	ft_printf("adresse de i: %p\nint (-2043): %d\n", &i, -2043);
	ft_printf("103 en hex: %x\n", 1703);
	ft_printf("103 en hex: %x\npourcent: %%\n", 1703);
	ft_printf("len: %d\n", ft_putnbr(1234567));
	ft_printf("printf len = %d\n", ft_printf("il y a %x 14 char", 1234));

	printf("\nchar (h): %c\nstr (Hello Louka): %s\n", 'h', "Hello Louka");
	printf("adresse de i: %p\nint (-2043): %d\n", &i, -2043);
	printf("1703 en hex: %x\n", 1703);
	printf("1703 en hex: %x\npourcent: %%\n", 1703);
	printf("len: %d\n", ft_putnbr(1234567));
	printf("printf len = %d\n", printf("il y a %x 14 char", 1234));
	return (0);
}*/
