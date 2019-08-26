#include "ft_printf.h"
#include <stdint.h>

char    *mirror(char *str, size_t len)
{
    size_t i;
    char tmp;

    i = 0;
    while (i < (len / 2))
    {
        tmp = str[i];
        str[i] = str[len - i -1];
        str[len - i - 1] = tmp;
        i++;
    }
    str[len] = '\0';
    return (str);
}

char    *ft_itoa_base(int64_t num, int base, int upper)
{
    char    *result;
    size_t  i;

    i = 0;
    if (base < 2 || base > 16 || (base != 10 && num < 0))
        return (NULL);
    if (base == 10)
        return (ft_itoa(num));
    if (!(result = (char *)malloc(64)))
        return (NULL);
    while (num)
    {
        if (base > 10 && (num % base) >= 10 && upper)
            result[i] = num % base - 10 + 'A';
        else if (base > 10 && (num % base) >= 10 && !upper)
            result[i] = num % base - 10 + 'a';
        else
            result[i] = num % base + '0';
        num /= base;
        i++;
    }
    result[i] = '\0';
    result = mirror(result, i);
    return (result);
}

int64_t     convert_num(int64_t num, int base, int upper)
{
    int64_t ret;
    char    *buff;

    buff = ft_itoa_base(num, base, upper);
    ret = ft_atoi_base(buff, base, upper);
    return (ret);
}
