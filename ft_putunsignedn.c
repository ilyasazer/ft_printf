/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignedn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazerou <ilazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:47:42 by ilazerou          #+#    #+#             */
/*   Updated: 2026/11/09 15:53:25 by ilazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsignedn(unsigned int nb)
{
	int	i;

	i = 1;
	if (nb > 9)
		i += ft_putunsignedn(nb / 10);
	ft_putchar(nb % 10 + '0');
	return (i);
}
