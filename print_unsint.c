/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:28:22 by teojimen          #+#    #+#             */
/*   Updated: 2023/10/19 17:28:22 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsint(unsigned int nb, int *count)
{
	if (*count == -1)
		return ;
	if (nb > 9)
	{
		print_int(nb / 10, count);
		print_int(nb % 10, count);
	}
	else
	{
		print_char(nb + '0', count);
		if (*count == -1)
			return ;
	}
}
