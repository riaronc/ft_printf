//
// Created by Oleksii DUSHKO on 2019-03-24.
//

#include "ft_printf.h"
#include "../lib/libft/libft.h"

int     print_s(char *str, char *flags, int p, int w)
{
    size_t len;
    char *buffer;
    t_flag *f;

    if(!(f = (t_flag *)malloc(sizeof(t_flag))))
        return (-42);
    f_init(flags, f);
    len = ft_strlen(str);
    len = len > p && p != -42 ? p : len;
    buffer = ft_strndup(str, (int)len);
    buffer = handle_min_width(buffer, w, len, f->minus, ' ');
    ft_putstr(buffer);
    free(buffer);
    return ((int)len);
}