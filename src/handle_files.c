#include "pipex.h"

int handle_files(int *file, char *arg, int flag)
{
	if(flag == IN)
	{
		if (access(arg, F_OK) != -1)
			return (open(arg, O_WRONLY ));
	}
	else if (flag == OUT)
	{
		if (access(arg, W_OK | X_OK) == -1)
			return (open(arg, O_CREAT | O_WRONLY | O_TRUNC, 0644));
		else
			return (open(arg, O_TRUNC, 0644));
	}
	return 0;
}