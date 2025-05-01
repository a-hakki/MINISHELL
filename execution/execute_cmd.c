/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:59:33 by ahakki            #+#    #+#             */
/*   Updated: 2025/05/01 11:26:29 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	execute_node(t_shell *vars, t_list *node)
{
	char	*cmd_path;

	cmd_path = get_path(*node->arr, vars);
	if (check_built_ins(node->arr, vars) == TRUE)
		vars->tmp = node->next;
	else if (!cmd_path)
		vars->tmp = node->next;
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
	return (TRUE);
}

int	execute_cmd(t_shell *vars, t_list *node)
{
	vars->exit = execute_node(vars, node);
	if (vars->exit && node->next->type == OR)
	{
		while (vars->exit && node->next->type == OR)
			node = node->next->next;
	}
	else if (!vars->exit && node->next->type == AND)
	{
		while (node->next->type == AND)
			node = node->next->next;
	}
	else if (vars->exit && node->next->type == AND)
		node = node->next->next;
	else if (!vars->exit && node->next->type == OR)
		node = node->next->next;
	return (vars->exit);
}