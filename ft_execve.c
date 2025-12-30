
#include "unistd.h"
#include <stdio.h>

void ft_execve(const char *exec_file, char *const *argv, char *const *envp)
{
	execve(exec_file, argv, envp);
	perror("ft_execve failed with: ");
 }
