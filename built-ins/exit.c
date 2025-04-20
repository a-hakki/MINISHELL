/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:19:39 by ahakki            #+#    #+#             */
/*   Updated: 2025/04/20 11:55:10 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_numeric_string(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return 0;
		str++;
	}
	return 1;
}

int	ft_exit(int ac, char **av, t_shell *vars)
{
	int exit_code;

	exit_code = 0;
	if (ac > 2)
	{
			vars->exit = 1;
			return (printfd(2, "exit\nexit: too many arguments\n"), FALSE);
	}
	if (ac == 2)
	{
		if (is_numeric_string(av[1]))
		{
			exit_code = (unsigned char)atoi(av[1]);
		}
		else
		{
			printfd(2, "minishell: exit: %s: numeric argument required\n", av[1]);
			exit_code = 2;
		}
	}
	vars->exit = exit_code;
	return (exit(exit_code), TRUE);
}
int main(int ac, char **av)
{
    t_shell vars;

    vars.exit = 0;

	ft_exit(ac, av, &vars);
	exit(vars.exit);
    return (0);
}
