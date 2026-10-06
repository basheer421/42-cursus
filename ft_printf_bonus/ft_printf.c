/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:56:33 by bammar            #+#    #+#             */
/*   Updated: 2022/08/23 17:46:39 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hexa(unsigned long long n, int small)
{
	unsigned long long	x;
	char				final[100];
	int					rem;
	int					i;
	int					j;

	x = n;
	i = 0;
	if (n == 0)
		return (ft_putchar_fd('0', 1));
	while (x != 0)
	{
		rem = x % 16;
		if (rem < 10)
			final[i++] = rem + '0';
		else
			final[i++] = ('A' + rem - 10) + (small * ('a' - 'A'));
		x = x / 16;
	}
	final[i] = 0;
	j = (int)ft_strlen(final);
	while (j >= 1)
		ft_putchar_fd(final[--j], 1);
	return ((int)ft_strlen(final));
}

static int	print_pointer(unsigned long long p)
{
	int	count;

	count = ft_putstr_fd("0x", 1);
	return (count + print_hexa(p, 1));
}

static int	ft_putunbr_fd(unsigned int n, int fd)
{
	int		count;
	char	c;

	c = '0';
	count = 0;
	if (n < 10)
	{
		c += n;
		count += ft_putchar_fd(c, 1);
	}
	else
	{
		count += ft_putunbr_fd(n / 10, fd);
		count += ft_putunbr_fd(n % 10, fd);
	}
	return (count);
}

static int	print_case(const char c, va_list ap)
{
	if (c == '%')
		return (ft_putchar_fd('%', 1));
	else if (c == 's')
		return (ft_putstr_fd((char *)va_arg(ap, char *), 1));
	else if (c == 'c')
		return (ft_putchar_fd(((char)va_arg(ap, int)), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd((int)va_arg(ap, int), 1));
	else if (c == 'u')
		return (ft_putunbr_fd(va_arg(ap, int), 1));
	else if (c == 'p')
		return (print_pointer(va_arg(ap, unsigned long long)));
	else if (c == 'x')
		return (print_hexa(va_arg(ap, unsigned int), 1));
	else if (c == 'X')
		return (print_hexa(va_arg(ap, unsigned int), 0));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		counter;

	va_start(ap, format);
	i = 0;
	counter = 0;
	while (format[i] != 0)
	{
		if (format[i] == '%')
			counter += print_case(format[i + 1], ap);
		else
			counter += ft_putchar_fd(format[i], 1);
		if (format[i] == '%' && format[i + 1] != 0)
			i += 2;
		else
			i++;
	}
	va_end(ap);
	return (counter);
}
