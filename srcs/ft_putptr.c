/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 10:42:14 by hadrider          #+#    #+#             */
/*   Updated: 2025/12/02 14:16:46 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putptr(void *ptr)
{
	int				i;
	int				count;
	char			hex[16];
	unsigned long	n;

	n = (unsigned long)ptr;
	i = 0;
	count = 0;
	if (!ptr)
		return (ft_putstr("0x0"));
	count += write(1, "0x", 2);
	while (n > 0)
	{
		hex[i++] = HEX_LOW_BASE[n % 16];
		n /= 16;
	}
	while (i > 0)
		count += write(1, &hex[--i], 1);
	return (count);
}
