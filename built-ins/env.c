/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:38:48 by sayed             #+#    #+#             */
/*   Updated: 2025/04/19 14:44:05 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	env(int ac, char **av, t_shell *vars)
{
	int	i;

	i = 0;
	(void)av;
	(void)vars;
	if (ac != 1)
		return (printfd(2, "env: No options or \
			arguments are allowed!\n"), TRUE);
	ft_putarr(vars->envp);
	// while (vars->envp && vars->envp[i])
	// {
	// 	if (ft_strchr(av[i], '='))
	// 		printf("%s\n", av[i]);
	// 	i++;
	// }
	return (TRUE);
}
