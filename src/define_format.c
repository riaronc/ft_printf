/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:31:48 by odushko           #+#    #+#             */
/*   Updated: 2019/03/21 20:40:44 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int64_t    converse_num(int64_t num, char *conv)
{
    if (ft_strcmp(conv, "h") == 0)
        num = (short int)num;
    else if (ft_strcmp(conv, "hh") == 0)
        num = (char)num;
    else if (ft_strcmp(conv, "l") == 0)
        num = (long)num;
    else if (ft_strcmp(conv, "ll") == 0)
        num = (long long)num;
    else
        exit(-1);
    return (num);
}

double    converse_fnum(double f_num, char *conv)
{
	if (ft_strcmp(conv, "h") == 0)
		f_num = (short int)f_num;
	else if (ft_strcmp(conv, "hh") == 0)
		f_num = (char)f_num;
	else if (ft_strcmp(conv, "l") == 0)
		f_num = (long)f_num;
	else if (ft_strcmp(conv, "ll") == 0)
		f_num = (long long)f_num;
	else
		exit(-1);
	return (f_num);
}

int    define_output(t_print *ar)
{
    int64_t num;
    int     ret;
    char    *str;
    double  f_num;

    ret = -42;
    if (ar->type == 'p')
    {
        char *flags;

        flags = ft_strdup(ar->flags);
        num = va_arg(ar->args, int64_t);
        flags = glue("#", flags);
        ret = print_xX(converse_num(num, "l\0"), flags, ar->precision, ar->min_width, ar->type);
        free(flags);
    }
    else if (ar->type == 'f')
    {
    	f_num = va_arg(ar->args, double);
	    if (ar->conversion[0] != 0)
		    f_num = converse_fnum(f_num, ar->conversion);
	    ret = print_f(f_num, ar->flags, ar->precision, ar->min_width);
    }
    else if (ar->type != 's')
    {
        num = va_arg(ar->args, int64_t);
        if (ar->conversion[0] != 0)
            num = converse_num(num, ar->conversion);
        if (ar->type == 'd' || ar->type =='i')
            ret = print_d(num, ar->flags, ar->precision, ar->min_width);
        if (ar->type == 'o')
            ret = print_o(num, ar->flags, ar->precision, ar->min_width);
        if (ar->type == 'u')
            ret = print_u(num, ar->flags, ar->precision, ar->min_width);
        if (ar->type == 'x' || ar->type == 'X')
            ret = print_xX(num, ar->flags, ar->precision, ar->min_width, ar->type);
        if (ar->type == 'c')
            ret = print_c(num, ar->flags, ar->min_width);
    }
    else if (ar->type == 's')
    {
        str = va_arg(ar->args, char *);
        ret = print_s(str, ar->flags, ar->precision, ar->min_width);
    }
    return (ret);
}

t_print *define_format(t_print *ar)
{
    check_for_flags(ar);
    check_for_min_width(ar);
    check_for_precision(ar);
    check_for_conversion(ar);
    check_for_type(ar);
    ar->ret = define_output(ar);
    return (ar);
}