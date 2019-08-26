//
// Created by Oleksii DUSHKO on 2019-03-24.
//

#include "ft_printf.h"

char   *handle_num_precision(char *str, int precision, size_t len, t_flag *f)
{
    char    *result;
    int     i;
    int     j;

    if (precision > (int)len)
    {
        i = -1;
        j = 0;
        if (!(result = (char *)malloc(precision + 1)))
            return (str);
        while (++i < precision - (int)len)
            result[i] = '0';
        while (i < precision)
            result[i++] = str[j++];
        result[i] = '\0';
        if (f->plus)
            result = glue("+", result);
        f->plus = 0;
        return (result);
    }
    if (f->plus)
        str = glue("+", str);
    f->plus = 0;
    return (str);
}