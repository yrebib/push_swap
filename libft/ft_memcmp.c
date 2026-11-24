/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorebib <yorebib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 14:21:18 by yorebib           #+#    #+#             */
/*   Updated: 2026/10/26 13:35:58 by yorebib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	if (str1 == str2)
		return (0);
	while (n > 0 && *str1 == *str2)
	{
		n--;
		str1++;
		str2++;
	}
	if (n == 0)
		return (0);
	return (*str1 - *str2);
}
