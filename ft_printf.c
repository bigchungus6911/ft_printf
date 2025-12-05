/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:56:39 by hadrider          #+#    #+#             */
/*   Updated: 2025/12/02 13:25:53 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_format(va_list *arg, char c, int *count)
{
	if (c == 's')
		*count += ft_putstr(va_arg(*arg, char *));
	else if (c == 'c')
		*count += ft_putchar(va_arg(*arg, int));
	else if (c == 'X')
		*count += ft_puthexup(va_arg(*arg, unsigned int));
	else if (c == 'x')
		*count += ft_puthexlow(va_arg(*arg, unsigned int));
	else if (c == 'p')
		*count += ft_putptr(va_arg(*arg, void *));
	else if (c == 'u')
		*count += ft_putunsigned(va_arg(*arg, unsigned int));
	else if (c == '%')
		*count += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		*count += ft_putnbr(va_arg(*arg, int));
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		count;

	va_start(arg, format);
	i = 0;
	count = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			handle_format(&arg, format[i], &count);
		}
		else
		{
			count += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(arg);
	return (count);
}
