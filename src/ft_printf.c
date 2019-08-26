/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:17:57 by odushko           #+#    #+#             */
/*   Updated: 2019/03/21 13:18:03 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_print  *ar_init(t_print *ar, const char *fmt)
{
    ar->format = ft_strdup(fmt);
    ft_bzero(ar->flags, 5);
    ft_bzero(ar->conversion, 3);
    ar->type = -42;
    ar->ret = 0;
    ar->precision = -42;
    ar->min_width = -42;
    return (ar);
}

int             ft_printf(const char *fmt, ...)
{
    t_print *ar;
    int     ret;

    if(!(ar = (t_print *)malloc(sizeof(t_print))))
        return (-42);
    ar->i = 0;
    while (fmt[ar->i] != '\0')
    {
        if (fmt[ar->i] == '%')
        {
            ar->i++;
            ar_init(ar, fmt);
            va_start(ar->args, fmt);
            define_format(ar);
            va_end(ar->args);
        }
        else
        {
            ft_putchar(fmt[ar->i]);
            ar->i++;
        }
    }
    //printf("%d\n", ar->min_width);
    ret = ar->ret;
    free(ar);
    return (ret);
}
