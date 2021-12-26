/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:46:05 by echrysta          #+#    #+#             */
/*   Updated: 2021/12/25 17:48:22 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_nbr(long n)
{
	int	i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static unsigned int	del_creat(int count)
{
	int				i;
	unsigned int	del;

	del = 1;
	i = 0;
	while (i != count - 1)
	{
		del = del * 10;
		i++;
	}
	return (del);
}

int	ft_putnbr_u_fd(unsigned int n, int fd)
{
	int				i;
	unsigned long	del;
	char			ch;
	int				count;

	i = 0;
	count = count_nbr(n);
	del = del_creat(count);
	while (i != count)
	{
		ch = (n / del) + '0';
		write(fd, &ch, 1);
		n = n % del;
		del = del / 10;
		i++;
	}
	return (count);
}
