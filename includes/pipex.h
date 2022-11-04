/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:43:40 by hbernard          #+#    #+#             */
/*   Updated: 2022/11/04 06:06:23 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>

#define IN 1
#define OUT 4
#define FIRST_ARG 2
#define SECOND_ARG 3

#define READ 0 
#define WRITE 1

#define OK 0

#define STDIN STDIN_FILENO
#define STDOUT STDOUT_FILENO

char	**pip_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int	exec_command(char **argv, char **envp);
void	free_alloc(char **str);
void	*ft_calloc(size_t nmemb, size_t size);


#endif