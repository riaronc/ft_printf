//
// Created by Oleksii DUSHKO on 2019-03-22.
//

#include "ft_printf.h"
#include <stdint.h>

int     print_o(int64_t num, char *flags, int p, int w)
{
    int ret;

    if (num > -1)
        num = convert_num(num, 8, 0);
    ret = print_d(num, flags, p, w);
    return (ret);
}
