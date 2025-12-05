/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:06:43 by hadrider          #+#    #+#             */
/*   Updated: 2025/12/02 14:15:10 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int nb)
{
	long	n;
	int		i;
	int		count;
	char	str[12];

	n = nb;
	i = 0;
	count = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	while (n > 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i > 0)
		count += write(1, &str[--i], 1);
	return (count);
}
