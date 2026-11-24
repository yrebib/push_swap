/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_fucs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorebib <yorebib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 20:50:02 by yorebib           #+#    #+#             */
/*   Updated: 2026/11/04 16:30:21 by yorebib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puts(char *str, int *count)
{
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
		{
			*count = -1;
			return ;
		}
		*count += 6;
		return ;
	}
	while (*str)
	{
		if (write(1, str, 1) == -1)
		{
			*count = -1;
			return ;
		}
		*count += 1;
		str++;
	}
}

void	ft_putid(long nbr, int *count)
{
	char	c;

	if (nbr < 0)
	{
		if (write(1, "-", 1) == -1)
		{
			*count = -1;
			return ;
		}
		*count += 1;
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putid(nbr / 10, count);
	if (*count == -1)
		return ;
	c = '0' + nbr % 10;
	if (write(1, &c, 1) == -1)
	{
		*count = -1;
		return ;
	}
	*count += 1;
}

void	ft_puthex(unsigned long nbr, int *count, char flag)
{
	char	*base;
	char	c;

	base = "0123456789abcdef";
	if (nbr > 15)
		ft_puthex(nbr / 16, count, flag);
	c = base[nbr % 16] - 32 * ((flag == 'X') && (nbr % 16 >= 10));
	if (write(1, &c, 1) == -1)
	{
		*count = -1;
		return ;
	}
	*count += 1;
}

void	ft_putux(unsigned long nbr, int *count, char flag)
{
	if (flag == 'u')
		ft_putid(nbr, count);
	else
		ft_puthex(nbr, count, flag);
}

void	ft_putp(void *ptr, int *count)
{
	unsigned long	adr;

	if (!ptr)
	{
		ft_puts("(nil)", count);
		return ;
	}
	adr = (unsigned long)ptr;
	if (write(1, "0x", 2) == -1)
	{
		*count = -1;
		return ;
	}
	*count += 2;
	ft_puthex(adr, count, 'x');
}
