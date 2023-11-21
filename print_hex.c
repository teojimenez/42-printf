/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:28:49 by teojimen          #+#    #+#             */
/*   Updated: 2023/10/19 17:28:49 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned int nb, int *count, int type, int flag)
{
	char	*hex;

	if (nb == 0 && flag > 0)
	{
		print_char('0', count);
		if (*count == -1)
			return ;
	}
	else if (nb != 0)
	{
		flag = 0;
		hex = "0123456789abcdef";
		print_hex(nb / 16, count, type, 0);
		if (*count == -1)
			return ;
		if (type == 1)
			hex = "0123456789ABCDEF";
		print_char(hex[nb % 16], count);
		if (*count == -1)
			return ;
	}
}
