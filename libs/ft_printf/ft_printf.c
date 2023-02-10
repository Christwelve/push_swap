/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:11:19 by cmeng             #+#    #+#             */
/*   Updated: 2023/01/29 21:49:45 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_specifier(const char *format, va_list args);

int	ft_printf(const char *format, ...)
{
	int		res;
	va_list	args;

	res = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			res += write (1, format, 1);
			format++;
		}
		else
		{
			format++;
			res += format_specifier(format, args);
			format++;
		}
	}
	va_end(args);
	return (res);
}

int	format_specifier(const char *format, va_list args)
{
	int		len;

	len = 0;
	if (*format == 'c')
		len += ft_putchar(va_arg(args, int ));
	if (*format == 's')
		len += ft_putstr(va_arg(args, char *), 0);
	if (*format == 'd' || *format == 'i')
		len += ft_putstr(ft_itoa(va_arg(args, int)), 1);
	if (*format == 'u')
		len += ft_putstr(ft_itoa_unsigned(va_arg(args, unsigned int)), 1);
	if (*format == 'p')
	{
		len += ft_putstr("0x", 0);
		len += ft_hex(va_arg(args, unsigned long));
	}
	if (*format == 'x')
		len += ft_hex(va_arg(args, unsigned int));
	if (*format == 'X')
		len += ft_hex_upper(va_arg(args, unsigned int));
	if (*format == '%')
		len += ft_putchar('%');
	return (len);
}
