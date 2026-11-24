/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorebib <yorebib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 08:43:16 by yorebib           #+#    #+#             */
/*   Updated: 2026/10/24 08:43:19 by yorebib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	i = 0;
	dlen = 0;
	while (dlen < size && dst[dlen])
		dlen++;
	slen = ft_strlen(src);
	if (dlen == size)
		return (size + slen);
	while (i + dlen + 1 < size && src[i])
	{
		dst[i + dlen] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (slen + dlen);
}
