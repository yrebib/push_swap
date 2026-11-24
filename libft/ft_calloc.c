/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorebib <yorebib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:02:25 by yorebib           #+#    #+#             */
/*   Updated: 2026/10/24 20:02:29 by yorebib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*buf;
	size_t			i;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (nmemb > ((size_t)-1) / size)
		return (NULL);
	buf = (unsigned char *)malloc(sizeof(char) * nmemb * size);
	if (!buf)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		buf[i++] = 0;
	return (buf);
}
