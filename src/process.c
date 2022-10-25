#include "pipex.h"

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
int read_file(int *fd1, char *infile)
{
    int     fd;
    int     size_file;
    char    **str;
    char    *arg[] = {"cat",infile, NULL};
    
    str = ft_split(infile,' ');
    size_file = strlen(str[0]);
    fd = access(infile, F_OK);
    if(fd == -1)
    {
        write(1,"bash: ",6);
        write(1,str[0],size_file);
        write(1,": ",2);
        perror("");
        return -1;
    }
    dup2(fd1[1], STDOUT_FILENO);
    close_fd(fd1);
    execve("/bin/cat", arg, NULL);
}