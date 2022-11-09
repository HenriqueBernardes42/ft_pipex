/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:20:39 by hbernard          #+#    #+#             */
/*   Updated: 2022/11/09 08:12:37 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

int		handle_files(char *arg, int flag);
void	free_alloc(char **com1, char **com2, char *com3);
void	error_handling(int exit_n, char *error_message);
void	free_pointer(char **args);


int	main(int argc, char **argv, char **envp)
{
	int	in;
	int	out;

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
		if (access(arg, F_OK | R_OK) == -1)
		{
			error_handling(NO_EXIT, arg);
			return (0);
		}
		else
			return (open(arg, O_RDONLY));
	}
	else if (flag == OUT)
	{
		if (access(arg, W_OK) == -1)
			error_handling(1, arg);
		else
			return (open(arg, O_CREAT | O_WRONLY | O_TRUNC, 0644));
	}
	return (0);
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

void free_pointer(char **args)
{
	int i;

	i = 0;
	while(args[i])
	{
		free(args[i]);
		++i;
	}	
	free(args);
}

void	error_handling(int exit_n, char *arg)
{
	char **args;
	
	args = pipex_split(arg,' ');
	write(2,"bash: ",ft_strlen("bash: "));
	write(2,args[0],ft_strlen(args[0]));
	write(2," :",1);
	free_pointer(args);
	perror("");
	if(exit_n != NO_EXIT)
		exit(exit_n);
}
