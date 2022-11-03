/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:23:36 by hbernard          #+#    #+#             */
/*   Updated: 2022/11/03 07:49:59 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char			*define_path(char *arg,char **envp);
static size_t	gen_strlen(char const *str, char delim);
static size_t	ft_word_counter(char const *s, char c);
static char		**split_it(char **split, char const *s, char c, size_t words);


void exec_command(char **argv, char **envp)
{  
	int		fd[2];
	int		pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[READ]);
		dup2(fd[WRITE], STDOUT);
		close(fd[WRITE]);
		execve(define_path(argv[FIRST_ARG], envp),pip_split(argv[FIRST_ARG],' '), NULL);
	} 
	close(fd[WRITE]);
	dup2(fd[READ], STDIN );
	close(fd[READ]);
	execve(define_path(argv[SECOND_ARG], envp),pip_split(argv[SECOND_ARG],' '), NULL);
}


char *define_path(char *arg,char **envp)
{
	char	**command;
	char	**path_plitted;
	char	*joined;
	int		i;

	i = 0;
	command = pip_split(arg, ' ');
	while (envp[++i])
	{
		if (ft_strncmp("PATH=", envp[i] , 5) == 0)
		{	
			path_plitted = pip_split(envp[i], ':');
			i = 0;
			command[0] = ft_strjoin("/", command[0]);
			while(access(joined, F_OK) == -1)
				joined = ft_strjoin(path_plitted[++i], command[0]);
			break;
		}
	}
	free_alloc(command);
	free_alloc(path_plitted);
	return (joined);
}

static size_t    gen_strlen(char const *str, char delim)
{
	size_t    i;

	i = 0;
	while (str[i] != delim && str[i])
		i++;
	return (i + 1);
}

static size_t    ft_word_counter(char const *s, char c)
{
	size_t    words;
	size_t    i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			if (s[i] == '\'')
			{
				i++;
				while (s[i] != '\'')
					i++;
			}
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

static char    **split_it(char **split, char const *s, char c, size_t words)
{
    size_t    i;
    size_t    j;
    int        len;

	i = 0;
	j = -1;
	while (++j < words)
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\'')
			len = gen_strlen(&s[++i], '\'');
		else
			len = gen_strlen(&s[i], c);
		split[j] = (char *)malloc(sizeof(char) * len);
		if (!split[j])
			return (NULL);
		if (s[i - 1] == '\'')
			ft_strlcpy(split[j], &s[i], len);
		else
			ft_strlcpy(split[j], &s[i], len);
		i += len;
	}
	return (split);
}

char    **pip_split(char const *s, char c)
{
	size_t	words;
	char	**split;
	
	words = ft_word_counter(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split_it(split, s, c, words);
	if (!split)
	{
		// ft_free_array(split, (void *)split);
		return (NULL);
	}
	split[words] = NULL;
	return (split);
}