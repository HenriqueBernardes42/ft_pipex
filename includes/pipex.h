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


int     check_outfile(char *out);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
static  char	**alloc(int count_words, char c, char const *s, char **split);
char	**ft_split(char const *s, char c);
void    child_proc(int *fd1, int *fd2,char *argv);
void    parent_proc(int *fd1, int *fd2,char *argv, char *out);
int    read_file(int *fd1, char *infile);
void    close_fd(int *fd);
char    *get_path(char *argv);
char    **get_args(char *argv);




