#include "pipex.h"

void close_fd(int *fd);
void read_file(int *fd1);
char *get_path(char *argv);
char **get_args(char *argv);

void child_proc(int *fd1, int *fd2,char *argv)
{
    dup2(fd1[0], STDIN_FILENO);
    close_fd(fd1);
    dup2(fd2[1], STDOUT_FILENO);
    close_fd(fd2);
    execve(get_path(argv), get_args(argv), NULL);
}

void parent_proc(int *fd1, int *fd2,char *argv, char *out)
{
    int fd_out;

    fd_out = open(out, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    close_fd(fd1);
    dup2(fd2[0], STDIN_FILENO);
    close_fd(fd2);
    dup2(fd_out, STDOUT_FILENO);
    close(fd_out);
    execve(get_path(argv), get_args(argv), NULL);
}
void read_file(int *fd1)
{
    char    *arg[] = {"cat","infile", NULL};
    
    dup2(fd1[1], STDOUT_FILENO);
    close_fd(fd1);
    execve("/bin/cat", arg, NULL);
}

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
        read_file(fd1);
    pipe(fd2);
    pid = fork();
    if(pid == 0)
        child_proc(fd1, fd2, argv[2]);
    parent_proc(fd1,fd2,argv[3], argv[4]);
    return (0);
}