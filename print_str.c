/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:28:28 by teojimen          #+#    #+#             */
/*   Updated: 2023/10/19 17:28:28 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(char *str, int *count)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		print_char(*str, count);
		if (*count == -1)
			return ;
		str++;
	}
}
