/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorebib <yorebib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 20:24:48 by yorebib           #+#    #+#             */
/*   Updated: 2026/11/04 16:49:05 by yorebib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_flag(char c)
{
	char	*flags;

	flags = "cspdiuxX%";
	while (*flags)
	{
		if (*flags == c)
			return (1);
		flags++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	if (!str)
		return (-1);
	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%' && ft_is_flag(*(str + 1)))
			ft_flag_task(&args, *(++str), &count);
		else
		{
			if ((*str == '%' && !*(str + 1)) || write(1, str, 1) == -1)
				count = -1;
			else
				count++;
		}
		if (count == -1)
			break ;
		str++;
	}
	va_end(args);
	return (count);
}
