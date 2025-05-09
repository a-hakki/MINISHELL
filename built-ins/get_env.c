/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:47:01 by ahakki            #+#    #+#             */
/*   Updated: 2025/04/30 14:39:51 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// char	*get_env(char *k, t_shell *vars)
// {
// 	int		i;
// 	char	**env;

// 	i = 0;
// 	if (!vars || !vars->envp || !k)
// 		return (NULL);
// 	env = vars->envp;
// 	while (env[i])
// 	{
// 		if (ft_strnstr(env[i], k, ft_strlen(k)) == env[i] \
// 			&& env[i][ft_strlen(k)] == '=')
// 			return (env[i] + ft_strlen(k) + 1);
// 		i++;
// 	}
// 	return (NULL);
// }

char	*get_env(char *k, t_shell *vars)
{
	t_list	*tmp;

	if (!vars || !vars->env || !k)
		return (NULL);
	tmp = vars->env;
	while (tmp)
	{
		if (ft_strnstr((char *)tmp->content, k, ft_strlen(k)) == (char *)tmp->content \
			&& ((char *)tmp->content)[ft_strlen(k)] == '=')
			return ((char *)tmp->content + ft_strlen(k) + 1);
		tmp = tmp->next;
	}
	return (NULL);
}

// int main(int ac, char **av, char **envp)
// {
// 	t_shell vars;

// 	vars.env = ft_arr2list(envp);
// 	printf("%s\n", get_env(av[1], &vars));
// 	return (0);
// }
