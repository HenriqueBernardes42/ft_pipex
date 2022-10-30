/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:43:40 by hbernard          #+#    #+#             */
/*   Updated: 2022/10/29 18:47:48 by hbernard         ###   ########.fr       */
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

int		check_outfile(char *out);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	child_proc(int *fd1, int *fd2, char *argv);
void	parent_proc(int *fd1, int *fd2, char *argv, int fd_out);
int		read_file(int *fd1, char *infile);
void	close_fd(int *fd);
char	*get_path(char *argv);
char	**get_args(char *argv);
int		check_command(char *argv);
int		check_args(int argc, char **argv);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

#endif