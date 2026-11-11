/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazerou <ilazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:54:04 by ilazerou          #+#    #+#             */
/*   Updated: 2026/11/09 18:21:03 by ilazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long int nb, int upper)
{
	int		i;
	char	*base;

	i = 1;
	if (!upper)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= 16)
		i += ft_puthex(nb / 16, upper);
	ft_putchar(base[nb % 16]);
	return (i);
}
