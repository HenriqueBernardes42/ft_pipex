/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:23:36 by hbernard          #+#    #+#             */
/*   Updated: 2022/10/30 17:28:31 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**create_arg(char **arg, char *arg1, char *arg2)
{
	arg = ft_calloc(4, sizeof(char *));
	arg[0] = arg1;
	arg[1] = arg2;
	arg[2] = NULL;
	return (arg);
}

void	child_proc(int *fd1, int *fd2, char *argv)
{
	char	*path;

	path = get_path(argv);
	if (access(path, F_OK) == -1)
	{
		perror("");
		free(path);
		exit(0);
	}
	free(path);
	dup2(fd1[0], STDIN_FILENO);
	close_fd(fd1);
	dup2(fd2[1], STDOUT_FILENO);
	close_fd(fd2);
	execve(get_path(argv), get_args(argv), NULL);
}

void	parent_proc(int *fd1, int *fd2, char *argv, int fd_out)
{
	char	*path;

	path = get_path(argv);
	if (access(path, F_OK) == -1)
	{
		free(path);
		perror("comand not found \n");
		exit(127);
	}
	free(path);
	close_fd(fd1);
	dup2(fd2[0], STDIN_FILENO);
	close_fd(fd2);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	execve(get_path(argv), get_args(argv), NULL);
}

int	read_file(int *fd1, char *infile)
{
	int		fd;
	int		size_file;
	char	**str;
	char	**arg;

	arg = NULL;
	arg = create_arg(arg, "cat", infile);
	str = ft_split(infile, ' ');
	size_file = ft_strlen(str[0]);
	fd = access(infile, F_OK);
	if (fd == -1)
	{
		free(str);
		perror("");
		exit(0);
	}
	dup2(fd1[1], STDOUT_FILENO);
	close_fd(fd1);
	execve("/bin/cat", arg, NULL);
	return (1);
}
