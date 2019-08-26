#include "ft_printf.h"

size_t     get_num_len(int64_t num)
{
    size_t len;

    len = 0;
    if (num < 0)
    {
        len++;
        num = -num;
    }
    while (num)
    {
        len++;
        num /= 10;
    }
    return (len);
}
