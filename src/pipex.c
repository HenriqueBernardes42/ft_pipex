/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:20:39 by hbernard          #+#    #+#             */
/*   Updated: 2022/11/04 05:01:23 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	close_fd(int *fd);
int		handle_files(int *file, char *arg, int flag);


int	main(int argc, char **argv, char **envp)
{
	int	in;
	int	out;
	
	open(argv[OUT], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	in = handle_files(&in, argv[IN], IN);
	out = handle_files(&out, argv[OUT], OUT);
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

int	handle_files(int *file, char *arg, int flag)
{
	if (flag == IN)
	{
		if (access(arg, F_OK ) == -1)
		{
			perror("infile invalido\n");
			exit(1);
		}
		else if (access(arg, R_OK ) == -1)
		{
			perror("infile sem permissão\n");
			exit(0);
		}
		else
			return (open(arg, O_RDONLY ));
	}
	else if (flag == OUT)
	{
		if (access(arg, F_OK | W_OK) == -1)
		{
			perror("sem outfile");
			exit(1);
		}
		else
			return (open(arg, O_CREAT | O_WRONLY | O_TRUNC, 0644));
	}
	return (0);
}