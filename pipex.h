#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
// #include <bsd/string.h>

#define W_FD 1
#define R_FD 0

#define FILE_NAME "outfile"

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
static  char	**alloc(int count_words, char c, char const *s, char **split);
char	**ft_split(char const *s, char c);




