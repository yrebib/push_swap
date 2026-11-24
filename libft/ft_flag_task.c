/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_task.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorebib <yorebib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 21:27:04 by yorebib           #+#    #+#             */
/*   Updated: 2026/11/02 09:48:19 by yorebib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putc(char c, int *count)
{
	if (write(1, &c, 1) == -1)
	{
		*count = -1;
		return ;
	}
	*count += 1;
}

void	ft_flag_task(va_list *arg, char flag, int *count)
{
	if (flag == 'i' || flag == 'd')
		ft_putid(va_arg(*arg, int), count);
	else if (flag == 'u' || flag == 'x' || flag == 'X')
		ft_putux(va_arg(*arg, unsigned int), count, flag);
	else if (flag == 's')
		ft_puts(va_arg(*arg, char *), count);
	else if (flag == 'p')
		ft_putp(va_arg(*arg, void *), count);
	else if (flag == 'c')
		ft_putc(va_arg(*arg, int), count);
	else
		ft_putc('%', count);
}
