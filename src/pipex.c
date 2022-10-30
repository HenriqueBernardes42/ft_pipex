/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:20:39 by hbernard          #+#    #+#             */
/*   Updated: 2022/10/30 16:47:45 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	free_split(char **command)
{
	int		i;

	i = 0;
	while (command[i])
		free(command[i++]);
	free(command);
}

char	*get_path(char *argv)
{
	char	*path;
	char	**command;

	command = ft_split(argv, ' ');
	path = ft_strjoin("/bin/", command[0]);
	free_split(command);
	return (path);
}

char	**get_args(char *argv)
{
	char	**str;
	size_t	argv_size;

	argv_size = ft_strlen(argv);
	str = ft_calloc(sizeof(argv), argv_size);
	*str = ft_strdup(argv);
	str = ft_split(str[0], ' ');
	return (str);
}

void	close_fd(int *fd)
{
	int	i;

	i = 0;
	while (i < 2)
		close(fd[i++]);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	fd1[2];
	int	fd2[2];
	int	fd_out;

	fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	check_args(argc, argv);
	pipe(fd1);
	pid = fork();
	if (pid == 0)
		read_file(fd1, argv[1]);
	pipe(fd2);
	pid = fork();
	if (pid == 0)
		child_proc(fd1, fd2, argv[2]);
	parent_proc(fd1, fd2, argv[3], fd_out);
	return (0);
}
