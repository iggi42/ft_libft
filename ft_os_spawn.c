#include "libft_mem.h"
#include "libft_os.h"
#include <unistd.h>
#include <stdlib.h>

t_os_proc	*ft_os_spawn(char *cmd, char *const *envp)
{
	int			fds[4];
	int			*f;
	t_os_proc	*result;

	f = (int *)&fds;
	result = (t_os_proc *)ft_malloc(sizeof(t_os_proc));
	if (result == NULL || pipe(f) || pipe(f + 2))
		return (NULL);
	result->pid = ft_spawn_cmd(cmd, envp, f + 1);
	result->stdin = fds[3];
	result->stdout = fds[0];
	result->stderr = STDERR_FILENO;
	if (result->pid > 0)
		return (result);
	free(result);
	return (NULL);
}
