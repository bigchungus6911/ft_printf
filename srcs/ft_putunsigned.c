/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:25:33 by hadrider          #+#    #+#             */
/*   Updated: 2025/12/02 13:27:05 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putunsigned(unsigned int nb)
{
	char	str[10];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (nb == 0)
		return (ft_putchar('0'));
	while (nb > 0)
	{
		str[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	while (i > 0)
		count += write(1, &str[--i], 1);
	return (count);
}
