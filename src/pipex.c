/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:20:39 by hbernard          #+#    #+#             */
/*   Updated: 2022/11/03 07:05:04 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	close_fd(int *fd);
int		handle_files(int *file, char *arg, int flag);


int	main(int argc, char **argv, char **envp)
{
	int	in;
	int	out;
	
	out = handle_files(&out, argv[OUT], OUT);
	in = handle_files(&in, argv[IN], IN);
	dup2(in, STDIN);
	dup2(out, STDOUT);
	exec_command(argv, envp);
	return (0);
}

void	close_fd(int *fd)
{
	int	i;

	i = 0;
	while (i < 2)
		close(fd[i++]);
}

int handle_files(int *file, char *arg, int flag)
{
	if(flag == IN)
	{
		if (access(arg, F_OK) != -1)
			return (open(arg, O_RDONLY ));
		else
		{
			perror("");
			exit(1);
		}
	}
	else if (flag == OUT)
	{
		if (access(arg, F_OK) == -1)
		{
			return open(arg, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		}
		else
			return (open(arg, O_TRUNC, 0644));
	}
	return 0;
}