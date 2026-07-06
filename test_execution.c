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
    t_cmd   *cmd3;

    (void)ac;
    (void)av;
    
    // 1. Initialize shell
    shell = shell_init(envp);

    // 2. Setup a pipeline: "ls -l" | "grep .c"
    char **args1 = malloc(sizeof(char *) * 3);
    args1[0] = ft_strdup("echo");
    args1[1] = ft_strdup("-n");
    args1[2] = ft_strdup("1");

    char **args2 = malloc(sizeof(char *) * 3);
    args2[0] = NULL;
    args2[1] = NULL;
    args2[2] = NULL;

    char **args3 = malloc(sizeof(char *) * 3);
    args3[0] = NULL; 
    args3[1] = NULL;
    args3[2] = NULL;


    cmd1 = create_cmd(args1);
    cmd2 = create_cmd(args2);
    cmd3 = create_cmd(args3);

    cmd1->next = NULL;
	cmd2->next = cmd3;
    
    shell->cmd = cmd1;

    // 3. Execute
    execution(shell);

    return (0);
}
