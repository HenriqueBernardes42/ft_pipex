#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			size1;
	int			size2;
	char		*ptr;

	size1 = strlen(s1);
	size2 = strlen(s2);
	ptr = calloc((size1 + size2 + 1), sizeof(char));
	if (ptr != NULL )
	{
		strncat(ptr, s1, size1 + 1);
		strncat(ptr, s2, size1 + size2 + 1);
		return (ptr);
	}
	else
		return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;
	size_t		s_len;

	i = 0;
	s_len = strlen(s);
	if (start > s_len)
		return (strdup(""));
	if ((s_len - start) < s_len)
		s_len = s_len - start;
	if (len < s_len)
		s_len = len;
	ptr = calloc((s_len + 1), sizeof(char));
	if (ptr != NULL)
	{
		while (i < len && s[start])
		{
			ptr[i] = s[start];
			++start;
			++i;
		}
		return (ptr);
	}
	return (NULL);
}

static char	**alloc(int count_words, char c, char const *s, char **split)
{
	int			i;
	int			start;
	size_t		end;
	size_t		s_len;

	start = 0;
	i = 0;
	s_len = strlen(s);
	while (i < count_words)
	{
		if (s[0] != c && i == 0)
			start = 0;
		else
		{
			while (s[start] == c)
				++start;
		}
		end = start;
		while (end < s_len && s[end] != c)
			++end;
		split[i] = ft_substr(s, start, end - start);
		++i;
		start = end;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int			count_words;
	char		**split;
	int			i;

	i = 0;
	count_words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			++count_words;
		++i;
	}
	split = calloc((count_words + 1), sizeof(char *));
	alloc(count_words, c, s, split);
	return (split);
}

// int main(int argv, char **argc)
// {
//     int     i;
//     char    **doc;
//     char    **saida;
//     char    *path;

//     i   = 2;
//     doc = malloc(sizeof(doc) * argv);
//     doc[0] = strdup(argc[2]);
//     saida = ft_split(doc[0], ' ');

//     path = ft_strjoin("/bin/", saida[0]);
//     printf("path == %s\n", path);
//     execve(path, saida, NULL);


//     return 0;
// }