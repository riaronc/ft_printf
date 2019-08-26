//
// Created by Oleksii DUSHKO on 2019-03-22.
//

#include "ft_printf.h"
#include <stdint.h>

static char   *tmp(char *result, const char *str, size_t len, int precision)
{
    int     i;
    int     j;

    i = -1;
    j = 0;
    while (++i < precision - len)
        result[i] = '0';
    while (i < precision)
    {
        result[i] = str[j];
        i++;
        j++;
    }
    result[i] = '\0';
    return (result);
}

static char   *handle_hex_precision(char *str, int precision, size_t len, t_flag *f, int upper)
{
    char    *result;

    if (precision > (int)len)
    {
        if (!(result = (char *)malloc(precision + 1)))
            return (str);
        result = tmp(result, str, len, precision);
        if (f->hash && !upper)
            result = glue("0x", result);
        else if (f->hash && upper)
            result = glue("0X", result);
        return (result);
    }
    if (f->hash && !upper)
        str = glue("0x", str);
    else if (f->hash && upper)
        str = glue("0X", str);
    return (str);
}

int     print_xX(int64_t num, char *flags, int p, int w, char type)
{
    size_t len;
    int upper;
    char *buffer;
    char space;
    t_flag  *f;

    if(!(f = (t_flag *)malloc(sizeof(t_flag))))
        return (-42);
    f_init(flags, f);
    upper = type == 'X' ? 1 : 0;
    buffer = ft_itoa_base(num, 16, upper);
    len = ft_strlen(buffer);
    buffer = handle_hex_precision(buffer, p, len, f, upper);
    space = (char)(f->zero == 1 && p < 0 ? '0' : ' ');
    buffer = handle_min_width(buffer, w, ft_strlen(buffer), f->minus, space);
    ft_putstr(buffer);
    len = ft_strlen(buffer);
    free(buffer);
    return ((int)len);
}