/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:23:36 by hbernard          #+#    #+#             */
/*   Updated: 2022/11/02 05:19:14 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *define_path(char *arg,char **envp);
char **define_command(char *arg);

void exec_command(char **argv, char **envp)
{
	int		fd[2];
	int		pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execve(define_path(argv[2], envp),define_command(argv[2]), NULL);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO );
	execve(define_path(argv[3], envp),define_command(argv[3]), NULL);
}


char *define_path(char *arg,char **envp)
{
	char	**command;
	char	**path_plitted;
	char	*joined;
	int		i;

	i = 0;
	command = ft_split(arg, ' ');
	while (envp[++i])
	{
		if (ft_strncmp("PATH=", envp[i] , 5) == 0)
		{	
			path_plitted = ft_split(envp[i], ':');
			i = 0;
			command[0] = ft_strjoin("/", command[0]);
			while(access(joined, F_OK) == -1)
				joined = ft_strjoin(path_plitted[++i], command[0]);
			break;
		}
	}
	return (joined);
}

char **define_command(char *arg)
{
	char	**str;
	size_t	argv_size;

	str = ft_split(arg, ' ');
	return (str);
}