/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:23:36 by hbernard          #+#    #+#             */
/*   Updated: 2022/11/10 14:10:37 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*define_path(char *arg, char **envp);
char	*find_path(char **envp);
void	child_process(int *fd, int fd_n, char *arg, char **envp);

void	exec_command(char **argv, char **envp, int in_OK)
{
	int		*fd;
	int		pid;
	int		status;

	fd = ft_calloc(3, sizeof(fd));
	pipe(fd);
	if (in_OK)
	{
		pid = fork();
		if (pid == 0)
			child_process(fd, STDOUT, argv[FIRST_ARG], envp);
	}
	pid = fork();
	if (pid == 0)
		child_process(fd, STDIN, argv[SECOND_ARG], envp);
	close(fd[WRITE]);
	close(fd[READ]);
	free(fd);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
}

void	child_process(int *fd, int fd_n, char *arg, char **envp)
{
	char	*path;
	int		not_used;

	if (fd_n == STDOUT)
		not_used = STDIN;
	else
		not_used = STDOUT;
	close(fd[not_used]);
	dup2(fd[fd_n], fd_n);
	close(fd[fd_n]);
	path = define_path(arg, envp);
	if (path == NULL && fd_n == STDOUT)
		error_handling(1, arg, 0);
	if (path == NULL && fd_n == STDIN)
		error_handling(127, arg, 0);
	execve(path, pipex_split(arg, ' '), NULL);
}

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i++])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (envp[i]);
	}
	return (NULL);
}

char	*define_path(char *arg, char **envp)
{
	char	**command;
	char	**path_plitted;
	char	*joined;
	char	*path;
	int		i;

	command = pipex_split(arg, ' ');
	path_plitted = pipex_split(find_path(envp), ':');
	path = ft_strjoin("/", command[0]);
	i = 0;
	while (path_plitted[i])
	{
		joined = ft_strjoin(path_plitted[i], path);
		if (access(joined, F_OK) == OK)
		{
			free_alloc(path_plitted, command, path);
			return (joined);
		}
		free(joined);
		++i;
	}
	free_alloc(path_plitted, command, path);
	return (NULL);
}
