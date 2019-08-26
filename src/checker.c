/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:18:20 by odushko           #+#    #+#             */
/*   Updated: 2019/03/21 13:18:26 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print *check_for_flags(t_print *ar)
{
    char    *flags;
    int     i;
    int     j;

    i = 0;
    j = 0;
    flags = "+- 0#\0";
    while (flags[j] != '\0')
    {
        if (flags[j] == ar->format[ar->i])
        {
            ar->flags[i] = flags[j];
            ar->i++;
            i++;
            j = -1;
        }
        j++;
    }
    return (ar);
}

t_print *check_for_min_width(t_print *ar)
{
    if (ar->format[ar->i] == '*')
    {
        ar->i++;
        ar->min_width = va_arg(ar->args, int);
    }
    if (ar->format[ar->i] > 48 && ar->format[ar->i] < 58)
        while (ar->format[ar->i] > 47 && ar->format[ar->i] < 58)
        {
            if(ar->min_width == -42)
                ar->min_width = 0;
            ar->min_width *= 10;
            ar->min_width += ar->format[ar->i] - 48;
            ar->i++;
        }
    return (ar);
}

t_print *check_for_precision(t_print *ar)
{
    if (ar->format[ar->i] == '.')
    {
        ar->i++;
        if (ar->format[ar->i] == '*')
        {
            ar->i++;
            ar->precision = va_arg(ar->args, int);
        }
        while (ar->format[ar->i] > 47 && ar->format[ar->i] < 58)
        {
            if(ar->precision == -42)
                ar->precision = 0;
            ar->precision *= 10;
            ar->precision += ar->format[ar->i] - 48;
            ar->i++;
        }
    }
    return (ar);
}

t_print *check_for_conversion(t_print *ar)
{
    char    *conversion;
    int     i;
    int     j;

    i = 0;
    j = 0;
    conversion = "lhL\0";
    while (conversion[j] != '\0')
    {
        if (conversion[j] == ar->format[ar->i])
        {
            ar->conversion[i] = conversion[j];
            ar->i++;
            i++;
            j = -1;
        }
        j++;
    }
    return (ar);
}

t_print *check_for_type(t_print *ar)
{
    char    *types;
    int     i;

    i = 0;
    types = "diouxXfcsp\0";
    while (types[i] != '\0')
    {
        if (types[i] == ar->format[ar->i])
        {
            ar->type = ar->format[ar->i++];
            break ;
        }
        i++;
    }
    return (ar);
}
