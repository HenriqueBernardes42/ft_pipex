/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:20:39 by hbernard          #+#    #+#             */
/*   Updated: 2022/11/01 18:31:40 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	close_fd(int *fd);
void	free_split(char **command);
char	*get_path(char *argv);
char	**get_args(char *argv);

int	main(int argc, char **argv, char **envp)
{
	int	in;
	int	out;
	
	in = handle_files(&in, argv[IN], IN);
	out = handle_files(&out, argv[OUT], OUT);
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
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