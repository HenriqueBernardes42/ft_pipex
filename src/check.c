/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:22:46 by hbernard          #+#    #+#             */
/*   Updated: 2022/10/29 08:27:13 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_outfile(char *out)
{
	int	fd;

	fd = access(out, F_OK);
	if (fd == -1)
	{
		fd = open(out, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		return (-1);
	}
	exit(EXIT_FAILURE);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 5)
		exit(1);
	while (i < argc)
	{
		if (access(argv[1], F_OK) == -1)
			exit(1);
		if (access(argv[1], R_OK) == -1)
		{
			perror("permission denied\n");
			exit(0);
		}
		if (access(argv[4], R_OK) == -1)
		{
			perror("permission denied\n");
			exit(1);
		}	
		++i;
	}
	return (0);
}
