#include <minishell.h>

t_shell	*shell_init(char **envp)
{
	t_shell	*shell;

	shell = (t_shell *)malloc(sizeof(t_shell));
	if (!shell)
		return (exit_error("Code erreur a definir: malloc failed", 3), NULL);
	shell->env = env_init(envp);
	return (shell);
}

static t_cmd *create_cmd(char **args)
{
    t_cmd *new = malloc(sizeof(t_cmd));
    new->cmd = args;
    new->in_fd = 0;   // Default to stdin
    new->out_fd = 1;  // Default to stdout
    new->next = NULL;
    return new;
}

int main(int ac, char **av, char **envp)
{
    t_shell *shell;
    t_cmd   *cmd1;
    t_cmd   *cmd2;

    (void)ac;
    (void)av;
    
    // 1. Initialize shell
    shell = shell_init(envp);

    // 2. Setup a pipeline: "ls -l" | "grep .c"
    char **args1 = malloc(sizeof(char *) * 3);
    args1[0] = ft_strdup("env");
    args1[1] = NULL;
    args1[2] = NULL;

    char **args2 = malloc(sizeof(char *) * 3);
    args2[0] = ft_strdup("grep");
    args2[1] = ft_strdup("PATH");
    args2[2] = NULL;

    cmd1 = create_cmd(args1);
    cmd2 = create_cmd(args2);
    cmd1->next = cmd2;
    
    shell->cmd = cmd1;

    // 3. Execute
    master_function(shell);

    return (0);
}
