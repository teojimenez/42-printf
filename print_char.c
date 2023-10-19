/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:28:37 by teojimen          #+#    #+#             */
/*   Updated: 2023/10/19 17:28:37 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char c, int *count)
{
	int	x;

	x = write(1, &c, 1);
	(*count) += x;
	if (x == -1)
		*count = -1;
}