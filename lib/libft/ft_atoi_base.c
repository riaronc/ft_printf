/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:56:12 by odushko           #+#    #+#             */
/*   Updated: 2019/03/22 18:02:03 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int b(int c, int base)
{
	char *str = "0123456789abcdef";
	char *str2 = "0123456789ABCDEF";
	int  i = 0;

   	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
   	return (-1);
}

int ft_atoi_base(const char *str, int base, int upper)
{
	int nb = 0;
	int sign = 1;
	int i = 0;
    char *bas;

	bas = upper == 1 ? "0123456789ABCDEF" : "0123456789abcdef";

	while (b(str[i], base) != -1)
	{
		nb = nb * base;
		nb = nb + bas[b(str[i], base)];
		i++;
	}
	return (sign * nb);
}
