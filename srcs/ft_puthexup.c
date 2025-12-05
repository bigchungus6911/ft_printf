/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:06:46 by hadrider          #+#    #+#             */
/*   Updated: 2025/12/02 12:56:46 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthexup(unsigned int nb)
{
	char	hex[16];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (nb == 0)
		return (ft_putchar('0'));
	while (nb > 0)
	{
		hex[i] = HEX_UP_BASE[nb % 16];
		nb /= 16;
		i++;
	}
	while (i > 0)
		count += write(1, &hex[--i], 1);
	return (count);
}
