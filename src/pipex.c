/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:20:39 by hbernard          #+#    #+#             */
/*   Updated: 2022/11/09 22:22:36 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

int		handle_files(char *arg, int flag);

int	main(int argc, char **argv, char **envp)
{
	int	in;
	int	out;

	if (argc != 5)
	{
		errno = ENOEXEC;
		perror("");
		exit(1);
	}
	in = handle_files(argv[IN], IN);
	if (argc != 5)
		exit(1);
	open(argv[OUT], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	out = handle_files(argv[OUT], OUT);
	dup2(in, STDIN);
	dup2(out, STDOUT);
	exec_command(argv, envp, in);
	return (0);
}

int	handle_files(char *arg, int flag)
{
	if (flag == IN)
	{
		if (access(arg, F_OK) == -1)
			error_handling(NO_EXIT, arg, ENOENT);
		else if (access(arg, R_OK) == -1)
			error_handling(NO_EXIT, arg, EACCES);
		else
			return (open(arg, O_RDONLY));
		return (0);
	}
	else if (flag == OUT)
	{
		if (access(arg, F_OK) == -1)
			error_handling(1, arg, ENOENT);
		else if (access(arg, W_OK) == -1)
			error_handling(1, arg, EACCES);
		else
			return (open(arg, O_CREAT | O_WRONLY | O_TRUNC, 0644));
	}
	return (0);
}
