/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:51:14 by echrysta          #+#    #+#             */
/*   Updated: 2021/12/25 17:51:53 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	rec(unsigned long long nbr, char *base, int *len)
{
	unsigned long long	n;
	unsigned long long	v;

	n = nbr;
	if (n > 16)
	{
		*len = *len + 1;
		v = n / 16;
		rec(v, base, len);
		ft_putchar_fd(base[n % 16], 1);
	}
	else if (nbr == 16)
	{
		*len = *len + 1;
		nbr = nbr / 16;
		rec(nbr, base, len);
		nbr--;
		ft_putchar_fd(base[nbr % 16], 1);
	}
	else
	{
		*len = *len + 1;
		ft_putchar_fd(base[n], 1);
	}
}

int	pointer(void *pointer)
{
	char	*base;
	int		len;

	len = 0;
	write(1, "0x", 2);
	len = 2;
	base = "0123456789abcdef";
	rec((unsigned long long)pointer, base, &len);
	return (len);
}
