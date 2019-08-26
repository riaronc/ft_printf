/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 10:34:52 by odushko           #+#    #+#             */
/*   Updated: 2018/11/02 11:33:00 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	len;
	char	*res;

	len = 0;
	if (s1 && s2)
	{
		while (s1[len] != '\0' || s2[len] != '\0')
			len++;
		if (!(res = ft_strnew(len)))
			return (NULL);
		i = -1;
		while (s1[++i] != '\0')
			res[i] = s1[i];
		j = 0;
		while (s2[j] != '\0')
		{
			res[i + j] = s2[j];
			j++;
		}
		return (res);
	}
	return (NULL);
}
