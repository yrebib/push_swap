/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorebib <yorebib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 18:46:18 by yorebib           #+#    #+#             */
/*   Updated: 2026/10/24 18:46:45 by yorebib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_how_many_str(char const *str, char sep)
{
	size_t	flag;
	size_t	count;

	flag = 0;
	count = 0;
	while (*str)
	{
		if (*str != sep && flag == 0)
		{
			count += ++flag;
			flag = 1;
		}
		else if (*str == sep)
			flag = 0;
		str++;
	}
	return (count);
}

static char	*ft_mydup(const char *str, char sep)
{
	char	*dest;
	size_t	i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != sep)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**ft_free_all(char **split, size_t n)
{
	while (n--)
		free(split[n]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	flag_i[2];

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_how_many_str(s, c) + 1));
	if (!split)
		return (NULL);
	flag_i[0] = 0;
	flag_i[1] = 0;
	while (*s)
	{
		if (*s != c && flag_i[0] == 0)
		{
			split[flag_i[1]++] = ft_mydup(s, c);
			if (!split[flag_i[1] - 1])
				return (ft_free_all(split, flag_i[1] - 1));
			flag_i[0] = 1;
		}
		else if (*s == c)
			flag_i[0] = 0;
		s++;
	}
	split[flag_i[1]] = NULL;
	return (split);
}
