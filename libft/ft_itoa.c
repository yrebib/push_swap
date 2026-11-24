/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorebib <yorebib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 18:46:58 by yorebib           #+#    #+#             */
/*   Updated: 2026/10/24 18:48:23 by yorebib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_to_allocat(int n)
{
	long	nb;
	int		size;

	if (n == 0)
		return (1);
	size = 0;
	nb = n;
	if (nb < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	nb;
	int		size;

	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	size = size_to_allocat(n);
	if (n < 0)
		nb = -nb;
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	result[size] = '\0';
	n = size - 1;
	while (nb > 0)
	{
		result[n--] = '0' + (nb % 10);
		nb /= 10;
	}
	return (result);
}
