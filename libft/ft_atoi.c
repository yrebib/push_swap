/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorebib <yorebib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 14:33:24 by yorebib           #+#    #+#             */
/*   Updated: 2026/10/26 12:14:21 by yorebib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long	nb;
	int		sign;

	sign = 1;
	nb = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (LONG_MAX);
		nb = nb * 10 + (*str++ - '0');
	}
	if (nb < INT_MIN || nb > INT_MAX)
		return (LONG_MAX);
	return (nb * sign);
}
