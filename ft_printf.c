/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:33:16 by echrysta          #+#    #+#             */
/*   Updated: 2021/12/25 17:39:32 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parsing(const char *string, va_list ap)
{
	int	len;

	len = 0;
	if (*string == 'c')
		len = ft_putchar_fd(va_arg(ap, int), 1);
	else if (*string == 's')
		len = ft_putstr_fd(va_arg(ap, char *), 1);
	else if (*string == 'p')
		len = pointer(va_arg(ap, void *));
	else if (*string == 'i' || *string == 'd')
		len = ft_putnbr_fd(va_arg(ap, int), 1);
	else if (*string == 'u')
		len = ft_putnbr_u_fd(va_arg(ap, unsigned int), 1);
	else if (*string == 'X')
		len = put_x(va_arg(ap, int), 'X');
	else if (*string == 'x')
		len = put_x(va_arg(ap, int), 'x');
	else if (*string == '%')
		len = ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *string, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			len = len + parsing(&string[i], ap);
		}
		else
			len = len + ft_putchar_fd(string[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
