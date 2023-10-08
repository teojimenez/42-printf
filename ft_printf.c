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

static int  p_format(char *str, )
{
    //cspdiuxX %
    //char
    //string
    //pointer(void)
    //doubleI
    //int
    //
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
            str++;
            p_format(str, args, &count);
        else()
            print_putchar();
    }
    va_end(args, str);
    //si falla el write, counter -1, para que falle todo
    //mientras  no sea % vaya imprimiendo y sumando count y augmentando format para que imprima cada char
    //cuando es % entra en otra funcion que segun el tipo lo evalua y lo imprime

}