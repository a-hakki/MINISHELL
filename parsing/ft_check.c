/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:30:19 by aelsayed          #+#    #+#             */
/*   Updated: 2025/04/04 18:04:30 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_shell	g_vars;

int	isvalid_syntax(void)
{
	t_list (*tmp) = g_vars._args;
	while (tmp)
	{
		if (tmp->content)
		{
			if (is_par((char *)tmp->content) && tmp->next && is_par((char *)tmp->next->content) && *(char *)tmp->content != *(char *)tmp->next->content)
				return (throw_error(OP), FALSE);
			if (!is_par((char *)tmp->content) && !is_op((char *)tmp->content) && tmp->next && is_par((char *)tmp->next->content) && *(char *)tmp->next->content == '(')
				return (throw_error(OP), FALSE);
			if (!is_par((char *)tmp->content) && is_op((char *)tmp->content) && tmp->next && is_par((char *)tmp->next->content) && *(char *)tmp->next->content == ')')
				return (throw_error(OP), FALSE);
			if (is_par((char *)tmp->content) && *(char *)tmp->content == '(' && tmp->next && is_op((char *)tmp->next->content) && *(char *)tmp->next->content != '<')
				return (throw_error(OP), FALSE);
			if (is_par((char *)tmp->content) && *(char *)tmp->content == ')' && tmp->next && !is_op((char *)tmp->next->content) && !is_par((char *)tmp->next->content))
				return (throw_error(OP), FALSE);
		}
		tmp = tmp->next;
	}
	return (TRUE);
}

int	ft_check(void)
{
	int	valid;

	valid = 0;
	valid += isvalid_quotes();
	valid += isvalid_op();
	valid += isvalid_syntax();
	valid += isvalid_par();
	valid += ft_nodejoin();
	if (valid != 5)
		return (FALSE);
	g_vars.tmp = g_vars.args;
	return (TRUE);
}
