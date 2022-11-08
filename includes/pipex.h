/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:43:40 by hbernard          #+#    #+#             */
/*   Updated: 2022/11/08 16:01:12 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>

# define IN 1
# define OUT 4
# define FIRST_ARG 2
# define SECOND_ARG 3

# define READ 0 
# define WRITE 1

# define OK 0

# define STDIN STDIN_FILENO
# define STDOUT STDOUT_FILENO

char	**pipex_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	exec_command(char **argv, char **envp);
void	free_alloc(char **com1, char **com2, char *com3);
void	*ft_calloc(size_t nmemb, size_t size);
void	error_handling(int exit_n, char *error_message);


#endif