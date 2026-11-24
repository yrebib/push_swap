/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorebib <yorebib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:03:55 by yorebib           #+#    #+#             */
/*   Updated: 2026/10/24 20:03:58 by yorebib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strdup(const char *s)
{
	char	*buf;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	buf = malloc(sizeof(char) * (i + 1));
	if (!buf)
		return (NULL);
	i = 0;
	while (s[i])
	{
		buf[i] = s[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
