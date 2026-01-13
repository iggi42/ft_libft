#include "libft_str.h"
#include "libft_os.h"
#include <unistd.h>

static char	*get_env(char *envp[], char *s)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	while (*(envp + i))
	{
		if (ft_strncmp(*(envp + i), s, slen) == 0 && *(*(envp + i)
				+ slen) == '=')
			return (*(envp + i) + slen + 1);
		i++;
	}
	return (NULL);
}

static char	*find_in_path(char *cmd0, char *envp[])
{
	char	**paths;
	size_t	i;
	char	*full_path;

	//needs to check for relative path in cmd0 instead of this
	if (access(cmd0, X_OK) == 0)
		return (cmd0);

	paths = ft_split(get_env(envp, "PATH"), ':');
	i = 0;
	while (*(paths + i))
	{
		full_path = ft_strf("%s/%s", *(paths + i), cmd0);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

void mk_std(int *pipes[2])
{
	if (pipes == NULL)
		return;
	dup2(*pipes[1], STDOUT_FILENO);
	dup2(*pipes[0], STDIN_FILENO);
}

// This doesn't handle envs in the beginning of the line yet
// nor dies it escape space via \ ' or "
pid_t	ft_spawn_cmd(char *cmd, char *const *envp, int **pipes)
{
	char	**cmd_ar;
	char	*exec_file;
	pid_t	result;

	cmd_ar = ft_split(cmd, ' ');
	exec_file = find_in_path(cmd_ar[0], (char **)envp);
	result = fork();
	if (result == 0)
	{
		mk_std(pipes);
		ft_execve(exec_file, cmd_ar, envp);
	}
	return (result);
}
