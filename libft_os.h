
typedef struct s_os_proc
{
	int stdin;
	int stdout;
	int stderr;
	int pid;
}		t_os_proc;

void	ft_fatal(void);
void	ft_execve(const char *exec_file, char *const *argv, char *const *envp);

int		ft_spawn_cmd(char *cmd, char *const *envp, int *redirects);

t_os_proc *ft_os_spawn(char *cmd, char *const *envp);

void ft_os_proc_cleanup(t_os_proc *proc);
