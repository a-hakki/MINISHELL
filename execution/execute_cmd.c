/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:59:33 by ahakki            #+#    #+#             */
/*   Updated: 2025/05/01 11:46:28 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	execute_node(t_shell *vars, t_list *node)
{
	char	*cmd_path;

	cmd_path = get_path(*node->arr, vars);
	if (check_builts(node->arr, vars) == TRUE)
		return (0);
	else if (!cmd_path)
		return (127);
	else
	{
		pid_t (pid) = fork();
		if (pid == 0)
		{
			if (execve(cmd_path, node->arr, vars->envp) == -1)
				perror("execve");
		}
		else
			wait(NULL);
	}
	free(cmd_path);
	return (0);
}

int	execute_cmd(t_shell *vars, t_list **node)
{
	vars->exit = execute_node(vars, (*node));
	if (vars->exit == 0 && (*node)->next->type == OR)
	{
		while (vars->exit == 0 && (*node)->next->type == OR)
			(*node) = (*node)->next->next;
	}
	else if (vars->exit != 0 && (*node)->next->type == AND)
	{
		while ((*node)->next->type == AND)
			(*node) = (*node)->next->next;
	}
	else if (vars->exit == 0 && (*node)->next->type == AND)
		(*node) = (*node)->next->next;
	else if (vars->exit != 0 && (*node)->next->type == OR)
		(*node) = (*node)->next->next;
	return (vars->exit);
}