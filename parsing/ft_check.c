/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:30:19 by aelsayed          #+#    #+#             */
/*   Updated: 2025/03/14 02:00:08 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_shell	g_vars;

int	ft_check(void)
{
	int	valid;

	valid = 0;
	valid += isvalid_quotes();
	valid += isvalid_op();
	valid += isvalid_par();
	valid += ft_nodejoin();
	if (valid != 4)
		return (FALSE);
	g_vars.tmp = g_vars.args;
	return (TRUE);
}
