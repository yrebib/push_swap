/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorebib <yorebib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 18:45:32 by yorebib           #+#    #+#             */
/*   Updated: 2026/10/24 18:46:07 by yorebib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_exist(const char *set, char target)
{
	if (!set)
		return (0);
	while (*set)
	{
		if (*set == target)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	str_len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	str_len = ft_strlen(s1);
	while (ft_is_exist(set, s1[str_len - 1]) && str_len >= 1)
		str_len--;
	if (!str_len)
		return (ft_strdup(""));
	while (ft_is_exist(set, s1[i]) && s1[i])
		i++;
	str = malloc(sizeof(char) * (str_len - i + 1));
	if (!str)
		return (NULL);
	ft_memmove(str, &s1[i], str_len - i);
	str[str_len - i] = '\0';
	return (str);
}
