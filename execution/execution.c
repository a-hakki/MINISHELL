/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:12:24 by aelsayed          #+#    #+#             */
/*   Updated: 2025/05/01 11:45:21 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_shell	g_vars;

int	check_builts(char **arr, t_shell *vars)
{
	if (!arr)
		return (FALSE);
	if (!ft_strcmp("pwd", *arr))
		return (pwd(ft_arrlen(arr), arr, vars), TRUE);
	if (!ft_strcmp("cd", *arr))
		return (cd(ft_arrlen(arr), arr, vars), TRUE);
	if (!ft_strcmp("echo", *arr))
		return (echo(ft_arrlen(arr), arr, vars), TRUE);
	if (!ft_strcmp("env", *arr))
		return (env(ft_arrlen(arr), arr, vars), TRUE);
	if (!ft_strcmp("exit", *arr))
		return (ft_exit(ft_arrlen(arr), arr, vars), TRUE);
	if (!ft_strcmp("export", *arr))
		return (export(ft_arrlen(arr), arr, vars), TRUE);
	if (!ft_strcmp("unset", *arr))
		return (unset(ft_arrlen(arr), arr, vars), TRUE);
	return (FALSE);
}

int	execution(t_shell *vars, t_list *ast)
{
	t_list	*node;

	// char	*cmd_path;
	node = ast;
	while (node)
	{
		if (node->type == CMD && !node->next)
		{
			vars->exit = execute_node(vars, &node);
			node = node->next;
			continue;
		}
		if (node->type == CMD && node->next->type <= AND)
			vars->exit = execute_cmd(vars, node);
		if (node->type == CMD && node->next && node->next->type == PIPE)
			vars->exit = pipex(vars, &node);
		// if (node->type == SUBSHELL)
			// vars->exit = execution(vars, node);
		// if (node->type == OR || node->type == AND)

		node = node->next;
	}
	return (vars->exit);
}
