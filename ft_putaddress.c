/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazerou <ilazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:14:21 by ilazerou          #+#    #+#             */
/*   Updated: 2026/11/10 18:29:13 by ilazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(void *add)
{
	int					i;
	unsigned long int	n;

	i = 0;
	n = (unsigned long int)add;
	if (!add)
		return (ft_putstr("(nil)"));
	i += ft_putstr("0x");
	i += ft_puthex(n, 0);
	return (i);
}
