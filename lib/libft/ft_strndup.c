/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:18:54 by odushko           #+#    #+#             */
/*   Updated: 2019/03/24 17:23:11 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, int len)
{
	int		i;
	char	*res;

	i = -1;
	if (!(res = (char *)malloc(len + 1)))
		return (NULL);
	while (++i < len && str[i] != '\0')
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}
