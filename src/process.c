/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:23:36 by hbernard          #+#    #+#             */
/*   Updated: 2022/11/04 06:58:40 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char			*define_path(char *arg,char **envp);
static size_t	gen_strlen(char const *str, char delim);
static size_t	ft_word_counter(char const *s, char c);
static char		**split_it(char **split, char const *s, char c, size_t words);
char			*find_path(char **envp);



void	exec_command(char **argv, char **envp)
{
	int		fd[2];
	int		pid;
	char	*path;
	int		status;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[READ]);
		dup2(fd[WRITE], STDOUT);
		close(fd[WRITE]);
		path = define_path(argv[FIRST_ARG], envp);
		dprintf(2,"path == %s\n", path);
		if(path == NULL)
		{
			perror("argumento 1 invalido");
			exit(1);
		}
		execve(path, pip_split(argv[FIRST_ARG],' '), NULL);
	}
	pid = fork();
	if (pid == 0)
	{
		close(fd[WRITE]);
		dup2(fd[READ], STDIN );
		close(fd[READ]);
		path = define_path(argv[SECOND_ARG], envp);
		if (path == NULL)
		{
			perror("argumento 2 invalido\n");
			exit(127);
		}
		execve(path,pip_split(argv[SECOND_ARG],' '), NULL);
	}
	close(fd[WRITE]);
	close(fd[READ]);
	waitpid(pid, &status, 0);
	if(WIFEXITED(status))
		exit(WEXITSTATUS(status));
}

char *find_path(char **envp)
{
	int i;

	i = 0;
	while(envp[i++])
	{
		if (ft_strncmp("PATH=", envp[i] , 5) == 0)
			return (envp[i]);
	}
	return NULL;
}

char *define_path(char *arg,char **envp)
{
	char	**command;
	char	**path_plitted;
	char	*joined;
	char	*path;
	int		i;

	command = pip_split(arg,' ');
	path_plitted = pip_split(find_path(envp), ':');
	path = ft_strjoin("/", command[0]);
	i = 0;
	while (path_plitted[i])
	{
		joined = ft_strjoin(path_plitted[i], path);
		if (access(joined, F_OK) == OK)
		{
			free(path);
			free_alloc(command);
			free_alloc(path_plitted);
			return (joined);
		}
		free(joined);
		++i;
	}
	free(path);
	free_alloc(command);
	free_alloc(path_plitted);
	return NULL;
}

static	size_t	gen_strlen(char const *str, char delim)
{
	size_t	i;

	i = 0;
	while (str[i] != delim && str[i])
		i++;
	return (i + 1);
}

static size_t	ft_word_counter(char const *s, char c)
{
	size_t	words;
	size_t	i;

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

static	char	**split_it(char **split, char const *s, char c, size_t words)
{
	size_t		i;
	size_t		j;
	int			len;

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
		split[j] = ft_calloc(sizeof(char) , len);
		if (!split[j])
			return (NULL);
		else
			ft_strlcpy(split[j], &s[i], len);
		i += len;
	}
	return (split);
}

char	**pip_split(char const *s, char c)
{
	size_t	words;
	char	**split;
	
	words = ft_word_counter(s, c);
	split = ft_calloc(sizeof(char *) , (words + 1));
	if (!split)
		return (NULL);
	split_it(split, s, c, words);
	return (split);
}