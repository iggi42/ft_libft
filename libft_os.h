
void	ft_fatal(void);
void	ft_execve(const char *exec_file, char *const *argv, char *const *envp);

int		ft_spawn_cmd(char *cmd, char *const *envp, int **pipes);
