#include "pipex.h"

char *get_path(char *argc)
{
    char *path;
    char **command;

    command = ft_split(argc, ' ');
    path = ft_strjoin("/bin/", command[0]);
    return (path);
}

char **get_args(char *argc)
{
    char    **str;
    size_t  argc_size;
    int     i;

    argc_size = strlen(argc);
    str = calloc(sizeof(argc) , argc_size);
    *str = strdup(argc);
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

int main(int argv, char **argc)
{
    int     pid;
    int     fd1[2];
    int     fd2[2];
    int     fd_out;
    char    *arg[] = {"cat","infile", NULL};
    char    **args;
    char    *path;


    fd_out = open("outfile", O_WRONLY);
    pipe(fd1);
    pid = fork();
    if(pid == 0)
    {
        dup2(fd1[1], STDOUT_FILENO);
        close_fd(fd1);
        execve("/bin/cat", arg, NULL);
    }

    path = get_path(argc[2]);
    args = get_args(argc[2]);
    printf("*********\npath = %s\nargs = %s\n******", path, args[0]);
    pipe(fd2);
    pid = fork();
    if(pid == 0)
    {
        dup2(fd1[0], STDIN_FILENO);
        close_fd(fd1);
        dup2(fd2[1], STDOUT_FILENO);
        close_fd(fd2);
        execve(path, args, NULL);
    }

    path = get_path(argc[3]);
    args = get_args(argc[3]);
    printf("*********\npath = %s\nargs = %s\n******", path, args[0]);
    pid = fork();
    if(pid == 0)
    {
        dup2(fd2[0], STDIN_FILENO);
        close_fd(fd2);
        dup2(fd1[1], STDOUT_FILENO);
        close_fd(fd1);
        execve(path, args, NULL);
    }

    path = get_path(argc[4]);
    args = get_args(argc[4]);
    printf("*********\npath = %s\nargs = %s\n******", path, args[0]);
    close_fd(fd2);
    dup2(fd1[0], STDIN_FILENO);
    close_fd(fd1);
    dup2(fd_out, STDOUT_FILENO);
    close(fd_out);
    execve(path, args, NULL);


    return (0);
}