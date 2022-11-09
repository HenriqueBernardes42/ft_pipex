/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:43:40 by hbernard          #+#    #+#             */
/*   Updated: 2022/11/09 21:51:55 by hbernard         ###   ########.fr       */
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
# include <stdio.h>
# include <errno.h>

# define IN 1
# define OUT 4
# define FIRST_ARG 2
# define SECOND_ARG 3

# define READ 0 
# define WRITE 1

# define OK 0
# define NO_EXIT -77

# define STDIN STDIN_FILENO
# define STDOUT STDOUT_FILENO

//pipex funcions
char	**pipex_split(char const *s, char c);
void	exec_command(char **argv, char **envp, int in_OK);
void	free_alloc(char **com1, char **com2, char *com3);
void	error_handling(int exit_n, char *arg, int err_status);
//libft funcions
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

#endif