/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:42:18 by teojimen          #+#    #+#             */
/*   Updated: 2023/10/06 21:42:18 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(char const *format, ...);
void	print_char(char c, int *count);
void	print_str(char *str, int *count);
void	print_int(int nb, int *count);
void	print_unsint(unsigned int nb, int *count);
void	print_hex(unsigned int nb, int *count, int type, int flag);
void	print_void(unsigned long nb, int *count, int flag, char *hex);

#endif