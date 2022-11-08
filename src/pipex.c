/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:20:39 by hbernard          #+#    #+#             */
/*   Updated: 2022/11/08 07:10:46 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	close_fd(int *fd);
int		handle_files(char *arg, int flag, int out);
void	free_alloc(char **com1, char **com2, char *com3);
void error_handling(int exit_n, char *error_message);


int	main(int argc, char **argv, char **envp)
{
	int	in;
	int	out;

	if (argc > 5)
		error_handling(1,"too many arguments!");
	if (argc < 5)
		error_handling(1,"too few arguments");
	out = open(argv[OUT], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	in = handle_files(argv[IN], IN, out);
	out = handle_files(argv[OUT], OUT, out);
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

int	handle_files(char *arg, int flag, int out)
{
	if (flag == IN)
	{
		if (access(arg, F_OK) == -1)
		{
			perror("infile not exist!");
			return out;
		}
		else if (access(arg, R_OK) == -1)
		{
			perror("infile perimission invalid!");
			return out;
		}
		else
			return (open(arg, O_RDONLY));
	}
	else if (flag == OUT)
	{
		if (access(arg, W_OK) == -1)
			error_handling(1,"outfile permission invalid!");
		else
			return (open(arg, O_CREAT | O_WRONLY | O_TRUNC, 0644));
	}
	return (0);
}

void	free_alloc(char **com1, char **com2, char *com3)
{
	int		i;

	i = 0;
	if (com1 == NULL)
		return ;
	while (com1[i])
		free(com1[i++]);
	free(com1);
	if (com2 == NULL)
		return ;
	i = 0;
	while (com2[i])
		free(com2[i++]);
	free(com2);
	free(com3);
}

void error_handling(int exit_n, char *error_message)
{
	perror(error_message);
	exit(exit_n);
}