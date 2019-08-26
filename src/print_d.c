/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:31:30 by odushko           #+#    #+#             */
/*   Updated: 2019/03/21 15:31:32 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int    print_d(int64_t num, char *flags, int p, int w)
{
    size_t  len;
    char    *buffer;
    char    space;
    t_flag    *f;

    if(!(f = (t_flag *)malloc(sizeof(t_flag))))
        return (-42);
    len = get_num_len(num);
    buffer = ft_itoa(num);
    f_init(flags, f);
    buffer = handle_num_precision(buffer, p, len, f);
    space = (char)(f->zero == 1 && p < 0 ? '0' : ' ');
    if (f->plus && !f->zero)
        buffer = glue ("+", buffer);
    else if (!f->plus && f->space)
        buffer = glue (" ", buffer);
    buffer = handle_min_width(buffer, w, ft_strlen(buffer), f->minus, space); //memory leak????
    if (f->plus && f->zero)
        buffer[0] = '+';
    ft_putstr(buffer);
    len = ft_strlen(buffer);
    free(f);
    free(buffer);
    return ((int) len);
}
