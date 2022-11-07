/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:09:31 by hbernard          #+#    #+#             */
/*   Updated: 2022/05/25 23:34:48 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	size_to_alloc;

	size_to_alloc = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size_to_alloc / nmemb == size)
	{
		ptr = malloc(size_to_alloc);
		if (ptr != NULL)
		{
			ft_bzero(ptr, size_to_alloc);
			return (ptr);
		}
	}
	return (0);
}
