#include "ft_printf.h"

char       *fill_gaps(size_t start, size_t end, char *where, char what)
{
    size_t i;

    i = start - 1;
    while (++i < end)
        where[i] = what;
    return (where);
}

char    *handle_min_width(char *str, int width, size_t len, int left_align, char space)
{
    char *ret;

    if ((size_t)width <= len)
        return (str);
    if (!(ret = (char *)malloc((size_t)width + 1)))
        return (str);
    ft_bzero(ret, (size_t)width + 1);
    if (left_align)
    {
        ret = glue(ret, str);
        ret = fill_gaps(len, (size_t)width, ret, space);
    }
    else
    {
        ret = fill_gaps(0, width - len, ret, space);
        ret = glue(ret, str);
    }
    ret[width] = '\0';
    return (ret);
}
