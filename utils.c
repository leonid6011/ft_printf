/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:52:26 by echrysta          #+#    #+#             */
/*   Updated: 2021/12/25 18:00:13 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

unsigned long	ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr_fd(char const *s, int fd)
{
	if (s == ((void *)0))
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		write(fd, s, ft_strlen(s));
		return ((int)ft_strlen(s));
	}
}

static void	rec(long nbr, char *base, int *len)
{
	long	n;
	long	v;

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

int	put_x(int nbr, char c)
{
	char		*base;
	int			len;
	long long	max;

	max = 4294967296;
	len = 0;
	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (nbr < 0)
	{
		max = max + (long)nbr;
		rec(max, base, &len);
	}
	else
		rec(nbr, base, &len);
	return (len);
}
