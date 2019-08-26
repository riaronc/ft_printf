#include "ft_printf.h"

char    *glue(const char *where, const char *from)
{
    int     i;
    int     j;
    char    *result;

    i = 0;
    j = 0;
    while (where[i] != '\0')
        i++;
    while (from[j] != '\0')
        j++;
    if(!(result = (char *)malloc((size_t)i + j + 1)))
        return (NULL);
    i = -1;
    j = -1;
    while (where[++i] != '\0')
        result[i] = where[i];
    while (from[++j] != '\0')
        result[i + j] = from[j];
    result[i + j] = '\0';
    return (result);
}