/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazerou <ilazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:31:58 by ilazerou          #+#    #+#             */
/*   Updated: 2026/11/11 16:15:30 by ilazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_type(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (c == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		i += ft_putaddress(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		i += ft_putunsignedn(va_arg(args, unsigned int));
	else if (c == 'x')
		i += ft_puthex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		i += ft_puthex(va_arg(args, unsigned int), 1);
	else if (c == '%')
		i += ft_putchar('%');
	else if (c == 'a')
		i += ft_putstr("Ilyass is the Best");
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			len += put_type(format[++i], args);
		else if (format[i] == '%' && !format[i + 1])
		{
			va_end(args);
			return (-1);
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

