/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:38:39 by teojimen          #+#    #+#             */
/*   Updated: 2023/10/17 22:33:20 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	p_format(char *str, va_list args, int *count)
{
	if (*str == 'c')
		print_char(va_arg(args, int), count);
	else if (*str == 's')
		print_str(va_arg(args, char *), count);
	else if (*str == 'i')
		print_int(va_arg(args, int), count);
	else if (*str == 'd')
		print_int(va_arg(args, int), count);
	else if (*str == 'u')
		print_unsint(va_arg(args, int), count);
	else if (*str == 'p')
		print_void(va_arg(args, unsigned long), count, 0, "0123456789abcdef");
	else if (*str == 'x')
		print_hex(va_arg(args, unsigned int), count, 0, 1);
	else if (*str == 'X')
		print_hex(va_arg(args, unsigned int), count, 1, 1);
	else if (*str == '%')
		print_char('%', count);
	else
		*count = -1;
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str && count != -1)
	{
		if (*str == '%')
		{
			str++;
			p_format((char *)str, args, &count);
		}
		else
			print_char(*str, &count);
		str++;
	}
	va_end(args);
	return (count);
}

// char *ft_char(char *c)
// {
//   return c;
// }

// #include <stdio.h>
// int main() {
//   int i = ft_printf("%c %i %s\n", 'h', 12, "Ho");
//   int j = printf("%c %i %s\n", 'h', 12, "Ho");
//   printf("%i - %i", i, j);
//   return 0;
// }

//va_list -> lista de todos los argumentos
//va_arg() -> para acceder al argumento (y su tipo)
//va_arg(argumento(list), tipo)
//va_start() -> iniciar los arg
//va_end() -> finalizar los arg

// • %i Imprime un entero en base 10.
// • %d Imprime un decimal en base 10.
// • %u Imprime un unsigned decimal en base 10.
// • %p El puntero void * dado como argumento se imprime en formato hexadecimal.
// • %x Imprime un número hexadecimal (base 16) en minúsculas.
// • %X Imprime un número hexadecimal (base 16) en mayúsculas.
// • % % para imprimir el símbolo del porcentaje.