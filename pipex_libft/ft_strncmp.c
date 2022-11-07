/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 06:13:56 by hbernard          #+#    #+#             */
/*   Updated: 2022/05/22 00:59:49 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] - s2[i] != 0)
		{
			if (s2[i] < 0)
				return (s1[i] - s2[i] * -1);
			if (s1[i] < 0)
				return (s1[i] * -1 - s2[i]);
			return (s1[i] - s2[i]);
		}
		++i;
	}
	return (0);
}
