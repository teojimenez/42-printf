/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:38:39 by teojimen          #+#    #+#             */
/*   Updated: 2023/10/08 19:38:39 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <stdarg.h>

static void print_putchar(char c, int *count)
{
    int x;

    x = write(1, &c, 1);
    (*count) += 1;
    if (x == -1)
        *count = -1;       
}

static void print_str(char *str, int *count)
{
    if (!str)
        // print_str("(null)", count);
        str = "(null)";
    while (*str)
    {
        print_putchar(*str, count);
        str++;
    }
}

static void print_int(int nb, int *count)
{
    if (nb <= -2147483648)
    {
        write(1, "-2147483648", 11);
        (*count) += 11;
        return ;
    }
    else if (nb < 0)
    {
        print_putchar('-', count);
        nb = -nb;
    }
    if (nb > 9)
    {
        print_int(nb / 10, count);
        print_int(nb % 10, count);
    }
    else
        print_putchar(nb + '0', count);
}

static void print_unsint(unsigned int nb, int *count)
{
    if (nb > 9)
    {
        print_int(nb / 10, count);
        print_int(nb % 10, count);
    }
    else
        print_putchar(nb + '0', count);
}

static void print_hex(unsigned int nb, int *count, int type, int flag)
{
    char *hex;

    if (nb == 0 && flag > 0)
    {
        print_putchar('0', count);
        return ;
    } 
    else if (nb != 0)
    {
        flag = 0;
        hex = "0123456789abcdef";
        print_hex(nb / 16, count, type, 0);
        if (type == 1)
            hex = "0123456789ABCDEF";
        print_putchar(hex[nb % 16], count);
    }
    if (nb == 0)
        return ;
}

static void print_void(unsigned long nb, int *count)
{
    print_str("0x", count);
    if (!nb)
        print_putchar('0', count);
    print_hex(nb, count, 0, 1);
}

static void  p_format(char *str, va_list args, int *count)
{
    //va_arg(list, type);
    if (*str == 'c')
        print_putchar(va_arg(args, int), count);
    else if (*str == 's')
        print_str(va_arg(args, char *), count);
    else if (*str == 'i') // • %i Imprime un entero en base 10.
        print_int(va_arg(args, int), count);
    else if (*str == 'd') // • %d Imprime un decimal en base 10.
        print_int(va_arg(args, int), count);
    else if (*str == 'u') // • %u Imprime un unsigned decimal en base 10.
        print_unsint(va_arg(args, int), count);

    else if (*str == 'p') // • %p El puntero void * dado como argumento se imprime en formato hexadecimal.
        print_void(va_arg(args, unsigned long), count);

    else if (*str == 'x') // • %x Imprime un número hexadecimal (base 16) en minúsculas.
        print_hex(va_arg(args, unsigned int), count, 0, 1);
    else if (*str == 'X') // • %X Imprime un número hexadecimal (base 16) en mayúsculas.
        print_hex(va_arg(args, unsigned int), count, 1, 1);
    else if (*str == '%') // • % % para imprimir el símbolo del porcentaje.
        print_putchar('%', count);
    else
        *count = -1;
}

int ft_printf(char const * str, ...)
{
    va_list args;
    int     count;

    count = 0;
    va_start(args, str);
    while (*str && count != -1)
    {
        if(*str == '%')
        {
            str++; //augmento para saber que retornara el tipo de funcion
            p_format((char *)str, args, &count);
        }
        else
            print_putchar(*str, &count);
        str++;
    }
    va_end(args);
    //si falla el write, counter -1, para que falle todo
    //mientras  no sea % vaya imprimiendo y sumando count y augmentando format para que imprima cada char
    //cuando es % entra en otra funcion que segun el tipo lo evalua y lo imprime
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