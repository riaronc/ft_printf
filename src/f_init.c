//
// Created by Oleksii DUSHKO on 2019-03-22.
//

#include "ft_printf.h"

t_flag      *f_init(char *flags, t_flag *f)
{
    f->plus = 0;
    f->minus = 0;
    f->hash = 0;
    f->space = 0;
    f->zero = 0;
    while (*flags != '\0')
    {
        if (*flags == '+')
            f->plus = 1;
        if (*flags == '-')
            f->minus = 1;
        if (*flags == ' ')
            f->space = 1;
        if (*flags == '0')
            f->zero = 1;
        if (*flags == '#')
            f->hash = 1;
        flags++;
    }
    return (f);
}