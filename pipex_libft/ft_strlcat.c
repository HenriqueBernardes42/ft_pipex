/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 04:55:35 by hbernard          #+#    #+#             */
/*   Updated: 2022/11/09 21:33:48 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((dst[i]) && (i < size))
		++i;
	while ((src[j]) && (j + i + 1 < size))
	{
		dst[i + j] = src[j];
		++j;
	}
	if (i < size)
		dst[j + i] = '\0';
	return (i + ft_strlen(src));
}
