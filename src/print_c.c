//
// Created by Oleksii DUSHKO on 2019-03-24.
//

#include "ft_printf.h"
#include <stdint.h>

int     print_c(int64_t num, char *flags, int w)
{
    size_t    len;
    char    *buffer;
    char    space;
    t_flag  *f;

    if(!(f = (t_flag *)malloc(sizeof(t_flag))))
        return (-42);
    f_init(flags, f);
    if(!(buffer = (char *)malloc(2)))
        return (-42);
    buffer[0] = ((char)num);
    buffer[1] = '\0';
    space = (char)(f->zero == 1 ? '0' : ' ');
    buffer = handle_min_width(buffer, w, 1, f->minus, space);
    len = ft_strlen(buffer);
    ft_putstr(buffer);
    free(buffer);
    return ((int)len);
}