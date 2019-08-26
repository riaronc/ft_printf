//
// Created by Oleksii DUSHKO on 2019-03-22.
//

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "../lib/libft/libft.h"

typedef struct  s_print
{
    const char  *format;
    char        flags[5];
    char        conversion[3];
    char        type;
    va_list     args;
    int         i;
    int         ret;
    int         precision;
    int         min_width;
}               t_print;

typedef struct  s_flags
{
    int         plus;
    int         minus;
    int         zero;
    int         space;
    int         hash;
}               t_flag;

char    *glue(const char *where, const char *from);
size_t  get_num_len(int64_t num);
int64_t convert_num(int64_t num, int base, int upper);
char    *ft_itoa_base(int64_t num, int base, int upper);
char    *mirror(char *str, size_t len);

int     ft_printf(const char *fmt, ...);
t_print *define_format(t_print *ar);

t_flag      *f_init(char *flags, t_flag *f);

t_print *check_for_conversion(t_print *ar);
t_print *check_for_precision(t_print *ar);
t_print *check_for_min_width(t_print *ar);
t_print *check_for_flags(t_print *ar);
t_print *check_for_type(t_print *ar);

int    print_d(int64_t num, char *flags, int p, int w);
int     print_o(int64_t num, char *flags, int p, int w);
int     print_u(int64_t num, char *flags, int p, int w);
int     print_xX(int64_t num, char *flags, int p, int w, char type);
int     print_c(int64_t num, char *flags, int w);
int     print_s(char *str, char *flags, int p, int w);
int     print_f(double num, char *flags, int p, int w);


char    *handle_min_width(char *str, int width, size_t len, int left_align, char space);
char    *handle_num_precision(char *str, int precision, size_t len, t_flag *f);

#endif
