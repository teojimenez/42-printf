/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:28:43 by teojimen          #+#    #+#             */
/*   Updated: 2023/10/19 17:28:43 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_min_number(int nb, int *count)
{
	if (nb <= -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
		{
			(*count) = -1;
			return (-1);
		}
		(*count) += 11;
		return (-1);
	}
	return (0);
}

void	print_int(int nb, int *count)
{
	if (*count == -1)
		return ;
	if (check_min_number(nb, count) == -1)
		return ;
	else if (nb < 0)
	{
		print_char('-', count);
		if (*count == -1)
			return ;
		nb = -nb;
	}
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
