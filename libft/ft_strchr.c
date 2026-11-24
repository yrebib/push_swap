/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorebib <yorebib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 08:44:50 by yorebib           #+#    #+#             */
/*   Updated: 2026/10/24 09:01:34 by yorebib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	slen;
	size_t	i;

	slen = 0;
	while (s[slen])
		slen++;
	i = 0;
	while (i <= slen)
	{
		if ((char)*(s + i) == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
