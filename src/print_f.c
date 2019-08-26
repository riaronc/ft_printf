//
// Created by Oleksii DUSHKO on 2019-03-27.
//

#include "ft_printf.h"

int     print_f(double num, char *flags, int p, int w)
{
	size_t ret;
	__uint128_t d_part;
	double f_part;
	char *buffer;
	int  p_copy;

	d_part = (__uint128_t)num;
	f_part = num - d_part;
	//printf("%lld\n", d_part);
	//printf("%f\n", f_part);
	if (p != 0)
		buffer = glue(ft_itoa(d_part), ".");
	else
		buffer = ft_itoa(d_part);
	p = p == -42 ? 6 : p;
	p_copy = p + 1;
	while (p > 0)
	{
		f_part *= 10;
		p--;
	}
	printf("\n%lld\n", (long long int)f_part);
	if (f_part != 0)
		buffer = glue(buffer, ft_itoa((__int128_t)f_part));
	else
		while (--p_copy > 0)
			buffer = glue(buffer, "0");
	ft_putstr(buffer);
	ret = ft_strlen(buffer);
	free(buffer);
	return ((int)ret);
}