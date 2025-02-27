/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:49:00 by aelsayed          #+#    #+#             */
/*   Updated: 2025/02/27 10:03:59 by ahakki           ###   ########.fr       */
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
}

int	ft_check(void)
{
	int		str_i;

	g_vars.tmp = g_vars.args;
	if ((g_vars.check.dquot % 2) || (g_vars.check.squot % 2) \
		|| (g_vars.check.par % 2))
		g_vars.check.special = 2;
	else
	{
		while (g_vars.tmp)
		{
			str_i = 0;
			while (((char *)g_vars.tmp->content)[str_i])
			{
				if (ft_strchr(";#\\", ((char *)g_vars.tmp->content)[str_i++]))
					g_vars.check.special = 1;
			}
			g_vars.tmp = g_vars.tmp->next;
		}
	}
	if (g_vars.check.special == 2 || g_vars.check.fpar == ')' \
		|| g_vars.check.lpar == '(')
		return (throw_error(SYNTAX), FALSE);
	if (g_vars.check.special == 1)
		return (throw_error(CHARS), FALSE);
	return (TRUE);
}

int	ft_isvalid(char c)
{
	if (c == '"')
		g_vars.check.dquot++;
	if (c == '\'')
		g_vars.check.squot++;
	if (c == '(')
	{
		g_vars.check.par++;
		g_vars.check.lpar = '(';
		if (g_vars.check.fpar == 0)
			g_vars.check.fpar = '(';
	}
	if (c == ')')
	{
		g_vars.check.par--;
		g_vars.check.lpar = ')';
		if (g_vars.check.fpar == 0)
			g_vars.check.fpar = ')';
	}
	return (TRUE);
}

int	betweenquotes(char	*str, char c)
{
	int	i;
	int	start;
	int	end;

	ft_init(8, &g_vars.check.dquot, &g_vars.check.squot, \
		&g_vars.check.par, &g_vars.check.special, &g_vars.check.fpar, \
			&g_vars.check.lpar, &i, &start);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		start = i + 1;
	end = ft_strlen(str);
	while (end > start && str[end] != c)
		end--;
	if (start != end)
	{
		while (str[start] && start < end)
			ft_isvalid(str[start++]);
		if ((g_vars.check.dquot % 2) || (g_vars.check.squot % 2) \
			|| (g_vars.check.par % 2))
			g_vars.check.special = 2;
	}
	return (g_vars.check.special++);
}

void	add_node(char *token)
{
	char	*trim;

	trim = ft_strtrim(token, " ");
	free(token);
	ft_lstadd_back(&g_vars.args, ft_lstnew(trim));
}

int	count_char(char *str, char c)
{
	int (count) = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

char	*new_join(char *str, char c)
{
	char	*result;

	int (i), (j);
	ft_init(2, &i, &j);
	if (!str)
		return (NULL);
	if (count_char(str, c) % 2)
		return (free(str), NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!result)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
	free(str);
	return (result);
}

int	fill_args(char *str)
{
	char	*token;

	str = new_join(str, '\'');
	str = new_join(str, '\"');
	if (!str)
		return (1);
	token = ft_strtok(str, "\"\'()|&><");
	while (token)
	{
		if (ft_strchr("\"\'()|&", *token))
			ft_isvalid(*token);
		add_node(token);
		token = ft_strtok(NULL, "\"\'()|&><");
	}
	if (ft_check())
	{
		g_vars.tmp = g_vars.args;
		betweenquotes(str, '\'');
		betweenquotes(str, '\"');
		if (g_vars.check.special > 1 || g_vars.check.fpar == ')' \
			|| g_vars.check.lpar == '(')
			return (throw_error(SYNTAX), 0);
	}
	return (ft_lstiter(g_vars.tmp, printf), 0);
}
