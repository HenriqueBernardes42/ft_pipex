/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:23:29 by hbernard          #+#    #+#             */
/*   Updated: 2022/11/09 21:24:15 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(int *fd)
{
	int	i;

	i = 0;
	while (i < 2)
		close(fd[i++]);
}

void	free_pointer(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		++i;
	}	
	free(args);
}

void	error_handling(int exit_n, char *arg, int err_status)
{
	char	**args;

	args = pipex_split(arg, ' ');
	write(2, "bash: ", ft_strlen("bash: "));
	write(2, args[0], ft_strlen(args[0]));
	free_pointer(args);
	if (err_status != 0)
	{
		write(2, ": ", ft_strlen(": "));
		errno = err_status;
		perror("");
	}
	else
		write(2, ": command not found\n", ft_strlen(": command not found\n"));
	if (exit_n != NO_EXIT)
		exit(exit_n);
}

void	free_alloc(char **com1, char **com2, char *com3)
{
	if (com1 == NULL)
		return ;
	free_pointer(com1);
	if (com2 == NULL)
		return ;
	free_pointer(com2);
	free(com3);
}
