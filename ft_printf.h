/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:40:27 by echrysta          #+#    #+#             */
/*   Updated: 2021/12/25 17:41:01 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char const *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	put_x(int i, char c);
int	pointer(void *pointer);
int	ft_putnbr_u_fd(unsigned int n, int fd);
int	ft_printf(const char *string, ...);

#endif
