#include "pipex.h"

char *get_path(char *argv)
{
    char *path;
    char **command;

    command = ft_split(argv, ' ');
    path = ft_strjoin("/bin/", command[0]);
    return (path);
}

char **get_args(char *argv)
{
    char    **str;
    size_t  argv_size;
    int     i;

    argv_size = strlen(argv);
    str = calloc(sizeof(argv) , argv_size);
    *str = strdup(argv);
    str = ft_split(str[0],' ');
    return str;
}

void close_fd(int *fd)
{
    int     i;
    
    i = 0;
    while(i < 2)
        close(fd[i++]);
}

int main(int argc, char **argv)
{
    int     pid;
    int     fd1[2];
    int     fd2[2];
    int     fd_out;

    pipe(fd1);
    pid = fork();
    if(pid == 0)
    {
        if(read_file(fd1, argv[1]) == -1)
            write(1,"0 outfile\n",10);
    }
    pipe(fd2);
    pid = fork();
    if(pid == 0)
        if(access(argv[1], F_OK) == 0)
            child_proc(fd1, fd2, argv[2]);
    if(access(argv[1], F_OK) == 0)
        parent_proc(fd1,fd2,argv[3], argv[4]);
    return (0);
}