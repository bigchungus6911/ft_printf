/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 09:35:04 by hadrider          #+#    #+#             */
/*   Updated: 2025/12/02 13:26:54 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	count = 0;
	while (str[i])
		count += write(1, &str[i++], 1);
	return (count);
}
