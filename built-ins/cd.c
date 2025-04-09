/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:06:14 by ahakki            #+#    #+#             */
/*   Updated: 2025/04/09 10:37:25 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cd(int ac, char **av, char **env)
{
	char	*oldpwd;
	char	*pwd;
	if (ac > 2)
		dprintf(2, "cd: too many arguments\n");
	oldpwd = getcwd(NULL, 0);
	if(chdir(av[1]))
	{
		dprintf(2, "cd: No such file or directory\n");
		return (free(oldpwd), FALSE);
	}
	pwd = getcwd(NULL, 0);
	
	return (TRUE);
}

int main(int ac, char **av, char **envp)
{
	cd(ac, av, getenv());
	return (0);
}