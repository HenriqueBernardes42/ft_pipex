/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 04:14:13 by hbernard          #+#    #+#             */
/*   Updated: 2022/11/09 21:33:44 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			size1;
	int			size2;
	char		*ptr;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	ptr = ft_calloc((size1 + size2 + 1), sizeof(char));
	if (ptr != NULL )
	{
		ft_strlcat(ptr, s1, size1 + 1);
		ft_strlcat(ptr, s2, size1 + size2 + 1);
		return (ptr);
	}
	else
		return (NULL);
}
