/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorebib <yorebib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:03:23 by yorebib           #+#    #+#             */
/*   Updated: 2026/10/24 20:03:26 by yorebib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*tmp2;
	char		*tmp1;

	tmp1 = (char *)dest;
	tmp2 = (const char *)src;
	while (n--)
		*tmp1++ = *tmp2++;
	return (dest);
}
