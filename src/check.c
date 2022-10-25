#include "pipex.h"

int check_outfile(char *out)
{
    int fd;

    fd = access(out, F_OK);
    if(fd == -1)
    {
        fd = open(out , O_CREAT | O_WRONLY | O_TRUNC, 0644);
        return -1;
    }

}