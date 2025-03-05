/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:49:00 by aelsayed          #+#    #+#             */
/*   Updated: 2025/03/05 19:29:46 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell	g_vars;

void	throw_error(int error)
{
	if (error == SYNTAX)
		printf("Invalid Syntax : Something is missing \" or ' or ( or )\n");
	if (error == CHARS)
		printf("Invalid Character => ; or \\ or #\n");
	g_vars.exit = 127;
}

// void	add_node(char *token)
// {
// 	char	*trim;

// 	trim = ft_strtrim(token, " ");
// 	free(token);
// 	ft_lstadd_back(&g_vars.args, ft_lstnew(trim));
// }
// 	// g_vars.cmd = removequotes(g_vars.cmd, '"');
// 	// g_vars.cmd = removequotes(g_vars.cmd, '\'');

int	isvalid_quotes(void)
{
	t_list (*tmp) = g_vars.args;
	int (len);
	while (tmp)
	{
		if (tmp->content)
		{
			len = ft_strlen((char *)tmp->content);
			if (((char *)tmp->content)[0] == '"' && \
			(((char *)tmp->content)[len - 1] != '"' || len == 1))
				return (throw_error(SYNTAX), FALSE);
		}
		if (tmp->content)
		{
			len = ft_strlen((char *)tmp->content);
			if (((char *)tmp->content)[0] == '\'' && \
			(((char *)tmp->content)[len - 1] != '\'' || len == 1))
				return (throw_error(SYNTAX), FALSE);
		}
		tmp = tmp->next;
	}
	return (TRUE);
}

int	is_op(char *str)
{
	if (str)
	{
		int (len) = ft_strlen(str);
		char (c) = str[0];
		if (len <= 2 && (c == '&' || c == '|'))
			return (TRUE);
	}
	return (FALSE);
}

int	is_par(char *str)
{
	if (str)
	{
		int (len) = ft_strlen(str);
		char (c) = str[0];
		if (len == 1 && (c == '(' || c == ')'))
			return (TRUE);
	}
	return (FALSE);
}

int	ft_isspace(char *str)
{
	int (i) = 0;
	if (str)
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\0')
			return (TRUE);
	}
	return (FALSE);
}

int	isvalid_op()
{
	t_list (*tmp) = g_vars.args;
	while (tmp)
	{
		if (tmp->content)
		{
			int (len) = ft_strlen((char *)tmp->content);
			if (len == 1 && ((char *)tmp->content)[0] == '&')
				return (throw_error(SYNTAX), FALSE);
			if (is_op((char *)tmp->content) && tmp->next && is_op((char *)tmp->next->content))
				return (throw_error(SYNTAX), FALSE);
			if (is_op((char *)tmp->content) && tmp->next && \
			ft_isspace((char *)tmp->next->content) && \
			tmp->next->next && is_op((char *)tmp->next->next->content))
				return (throw_error(SYNTAX), FALSE);
		}
		tmp = tmp->next;
	}
	return (TRUE);
}

void	ft_nodejoin()
{
	t_list (*tmp) = g_vars.args;
	t_list (*to_delete);
	char (*new_content);
	while (tmp && tmp->next)
	{
		if (!is_op((char *)tmp->content) && !is_op((char *)tmp->next->content) && \
		!is_par((char *)tmp->content) && !is_par((char *)tmp->next->content))
		{
			new_content = ft_strjoin((char *)tmp->content, (char *)tmp->next->content);
			if (!new_content)
				return;
			free(tmp->content);
			tmp->content = new_content;
			to_delete = tmp->next;
			tmp->next = tmp->next->next;
			ft_lstdelone(to_delete, free);
		}
		else
			tmp = tmp->next;
	}
}


int	fill_args(void)
{
	char (*token);
	if (!g_vars.cmd || !*(g_vars.cmd))
		return (0);
	token = ft_strtok(g_vars.cmd, "'\"()|&><");
	while (token)
	{
		ft_lstadd_back(&g_vars.args, ft_lstnew(token));
		token = ft_strtok(NULL, "'\"()|&><");
	}
	if (!isvalid_quotes() || !isvalid_op())
		return (FALSE);
	ft_nodejoin();
	g_vars.tmp = g_vars.args;
	return (ft_lstiter(g_vars.tmp, printf), 0);
}
