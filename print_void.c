/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_void.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:28:12 by teojimen          #+#    #+#             */
/*   Updated: 2023/10/19 17:28:12 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_void(unsigned long nb, int *count, int flag, char *hex)
{
	if (*count == -1)
		return ;
	if (flag == 0)
	{
		print_str("0x", count);
		if (*count == -1)
			return ;
	}
	if (!nb && flag == 0)
	{
		print_char('0', count);
		return ;
	}
	flag = 1;
	if (nb == 0)
		return ;
	if (nb != 0)
	{
		print_void(nb / 16, count, 1, "0123456789abcdef");
		print_char(hex[nb % 16], count);
		if (*count == -1)
			return ;
	}
}
