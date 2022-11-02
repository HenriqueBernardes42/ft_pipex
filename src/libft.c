#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] - s2[i] != 0)
		{
			if (s2[i] < 0)
				return (s1[i] - s2[i] * -1);
			if (s1[i] < 0)
				return (s1[i] * -1 - s2[i]);
			return (s1[i] - s2[i]);
		}
		++i;
	}
	return (0);
}