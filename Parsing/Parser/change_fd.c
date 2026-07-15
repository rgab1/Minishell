/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:16:18 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/15 17:18:40 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	manage_fd(t_tokens **tokens, t_cmd *cmd, int redir)
{
	if (((*tokens)->type == redir) && (redir == REDIR_IN))
	{
		if(change_fd_redir_in(tokens, cmd) == -1)
			return (-1);
	}
	else if ((*tokens)->type == redir && (redir == REDIR_OUT))
	{
		if(change_fd_redir_out(tokens, cmd) == -1)
			return (-1);
	}
	//else if ((*tokens)->type == redir && (redir == HREDIR_IN))
		// gestion heredoc 
		//A FAIRE !!!
	else if ((*tokens)->type == redir && (redir == AREDIR_OUT))
	{
		if(change_fd_aredir_out(tokens, cmd) == -1)
			return (-1);
	}
	if (cmd->in_fd == -1 || cmd->out_fd == -1)
	{
		perror((*tokens)->data);
		return (-1);
	}
	return (0);
}

int    change_fd_redir_in(t_tokens **tokens, t_cmd *cmd)
{
    *tokens = (*tokens)->next;
	if (*tokens == NULL)
		return (-1);
	if (cmd->in_fd != -2)
	{
		close(cmd->in_fd);
		cmd->in_fd = -2;
	}
	cmd->in_fd = open((*tokens)->data, O_RDONLY);
    return (0);
}

int    change_fd_redir_out(t_tokens **tokens, t_cmd *cmd)
{
    *tokens = (*tokens)->next;
	if (*tokens == NULL)
		return (-1);
	if (cmd->out_fd != -2)
	{
		close(cmd->out_fd);
		cmd->out_fd = -2;
	}
	cmd->out_fd = open((*tokens)->data, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    return (0);
}

int    change_fd_aredir_out(t_tokens **tokens, t_cmd *cmd)
{
    *tokens = (*tokens)->next;
	if (*tokens == NULL)
		return (-1);
    if (cmd->out_fd != -2)
	{
		close(cmd->out_fd);
		cmd->out_fd = -2;
	}
    cmd->out_fd = open((*tokens)->data, O_WRONLY | O_CREAT | O_APPEND, 0644);
    return (0);
}

// int manage_fd(t_tokens **tokens, t_cmd *cmd, int redir)
// {
//     dprintf(2, "[TRACE] manage_fd : Entrée avec la redirection type %d\n", redir);
//     if ((*tokens)->next == NULL || (*tokens)->next->data == NULL)
//     {
//         dprintf(2, "[TRACE] manage_fd : Erreur, pas de fichier après la redirection\n");
//         return (-1);
//     }
        
//     if (((*tokens)->type == redir) && (redir == REDIR_IN))
//     {
//         dprintf(2, "[TRACE] manage_fd : Appel de change_fd_redir_in\n");
//         if(change_fd_redir_in(tokens, cmd) == -1)
//             return (-1);
//     }
//     else if ((*tokens)->type == redir && (redir == REDIR_OUT))
//     {
//         dprintf(2, "[TRACE] manage_fd : Appel de change_fd_redir_out\n");
//         if(change_fd_redir_out(tokens, cmd) == -1)
//             return (-1);
//     }
//     else if ((*tokens)->type == redir && (redir == AREDIR_OUT))
//     {
//         dprintf(2, "[TRACE] manage_fd : Appel de change_fd_aredir_out\n");
//         if(change_fd_aredir_out(tokens, cmd) == -1)
//             return (-1);
//     }
        
//     if (cmd->in_fd == -1 || cmd->out_fd == -1)
//     {
//         dprintf(2, "[TRACE] manage_fd : Erreur de fd (-1)\n");
//         perror((*tokens)->data);
//         return (-1);
//     }
    
//     dprintf(2, "[TRACE] manage_fd : Fin avec succès\n");
//     return (0);
// }

// int    change_fd_redir_in(t_tokens **tokens, t_cmd *cmd)
// {
//     dprintf(2, "[TRACE] change_fd_redir_in : Avancée du pointeur vers le fichier\n");
//     *tokens = (*tokens)->next;
//     if (*tokens == NULL)
//         return (-1);
        
//     dprintf(2, "[TRACE] change_fd_redir_in : Fichier cible = '%s'\n", (*tokens)->data);
//     if (cmd->in_fd != -2)
//     {
//         close(cmd->in_fd);
//         cmd->in_fd = -2;
//     }
//     cmd->in_fd = open((*tokens)->data, O_RDONLY);
//     return (0);
// }

// int    change_fd_redir_out(t_tokens **tokens, t_cmd *cmd)
// {
//     dprintf(2, "[TRACE] change_fd_redir_out : Avancée du pointeur vers le fichier\n");
//     *tokens = (*tokens)->next;
//     if (*tokens == NULL)
//         return (-1);
        
//     dprintf(2, "[TRACE] change_fd_redir_out : Fichier cible = '%s'\n", (*tokens)->data);
//     if (cmd->out_fd != -2)
//     {
//         close(cmd->out_fd);
//         cmd->out_fd = -2;
//     }
//     cmd->out_fd = open((*tokens)->data, O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     return (0);
// }

// int    change_fd_aredir_out(t_tokens **tokens, t_cmd *cmd)
// {
//     dprintf(2, "[TRACE] change_fd_aredir_out : Avancée du pointeur vers le fichier\n");
//     *tokens = (*tokens)->next;
//     if (*tokens == NULL)
//         return (-1);
        
//     dprintf(2, "[TRACE] change_fd_aredir_out : Fichier cible = '%s'\n", (*tokens)->data);
//     if (cmd->out_fd != -2)
//     {
//         close(cmd->out_fd);
//         cmd->out_fd = -2;
//     }
//     cmd->out_fd = open((*tokens)->data, O_WRONLY | O_CREAT | O_APPEND, 0644);
//     return (0);
// }