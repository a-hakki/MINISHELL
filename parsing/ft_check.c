/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:30:19 by aelsayed          #+#    #+#             */
/*   Updated: 2025/05/30 06:40:03 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_nodejoin(t_shell *vars)
{
	char	*new_content;
	char	*tmp_content;
	t_list	*tmp;

	tmp = vars->args;
	while (tmp && tmp->next)
	{
		tmp_content = (char *)tmp->content;
		if (is_red(tmp_content, 'w') && \
			is_red((char *)tmp->next->content, 'w'))
		{
			new_content = alloc(0, ft_strjoin(tmp_content, \
				(char *)tmp->next->content), 0);
			if (!new_content)
				return (FALSE);
			tmp->content = new_content;
			tmp->next = tmp->next->next;
		}
		else
			tmp = tmp->next;
	}
	return (TRUE);
}

int	isvalid_syntax(t_shell *vars)
{
	t_list	*tmp;
	char	*c;
	char	*n;

	tmp = vars->args;
	while (tmp)
	{
		c = (char *)tmp->content;
		if (tmp->next)
			n = alloc(0, ft_strtrim((char *)tmp->next->content, WHITE), 0);
		if (is_par(c) && tmp->next && is_par(n) && *c != *n)
			return (throw_error(SYNTAX, n, NULL), FALSE);
		if (!is_par(c) && !is_op(c) && tmp->next && is_par(n) && *n == '(')
			return (throw_error(SYNTAX, n, NULL), FALSE);
		if (!is_par(c) && is_op(c) && tmp->next && is_par(n) && *n == ')')
			return (throw_error(SYNTAX, n, NULL), FALSE);
		if (is_par(c) && *c == ')' && tmp->next && !is_op(n) && \
			!is_par(n) && !is_there_red(n))
			return (throw_error(SYNTAX, n, NULL), FALSE);
		if (is_par(c) && *c == '(' && tmp->next && is_op(n))
			return (throw_error(SYNTAX, n, NULL), FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

void	pop_spaces(t_shell *vars)
{
	t_list	*new;
	t_list	*tmp;
	t_list	*next;
	t_list	*node;

	tmp = vars->args;
	new = NULL;
	while (tmp)
	{
		next = tmp->next;
		if (ft_iswhitespace(tmp->content) == FALSE)
		{
			node = ft_lstnew(alloc(0, ft_strdup(tmp->content), 0));
			node->arr = ft_arrdup(tmp->arr);
			ft_lstadd_back(&new, alloc(0, node, 0));
		}
		tmp = next;
	}
	vars->args = new;
}

int	all_checks(t_shell *vars)
{
	if (vars->args && is_op((char *)vars->args->content))
		return (throw_error(SYNTAX, (char *)vars->args->content, NULL), 0);
	if (isvalid_quotes(vars) == FALSE)
		return (FALSE);
	if (isvalid_par(vars) == FALSE)
		return (FALSE);
	if (ft_nodejoin(vars) == FALSE)
		return (FALSE);
	pop_spaces(vars);
	if (isvalid_syntax(vars) == FALSE)
		return (FALSE);
	if (isvalid_red(vars) == FALSE)
		return (FALSE);
	if (isvalid_op(vars) == FALSE)
		return (FALSE);
	return (TRUE);
}

void	throw_error(int error, char *file, int *exitt)
{
	if (error == EOOF)
		printfd(1, M": warning: here-document at line \
%d delimited by end-of-file (wanted `%s')\n", *exitt, file);
	if (error == ENOENT || error == EACCES)
		printfd(2, M": %s: %s\n", file, strerror(error));
	if (error == SYNTAX)
		printfd(2, M": syntax error near unexpected token `%s'\n", file);
	if (error == CMD_NOT_FOUND)
		printfd(2, "%s: command not found\n", file);
	if (error == DIRECT)
		printfd(2, M": Cannot open current working directory\n");
	if (error == REDIR)
		printfd(2, M": %s: ambiguous redirect\n", file);
}
