/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:10:45 by ahakki            #+#    #+#             */
/*   Updated: 2025/02/16 20:54:53 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env) {
	char	*s = readline("minishell>");
	char	**splited = ft_split(s, ' ');
	int i = 0;
	int j = 0;

	(void)ac;
	(void)av;
	// (void)env;
	while (splited[i])
		printf("%s\n", splited[i++]);
	ft_free("2", splited);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			splited = ft_split(env[i], ':');
			while (splited[j])
			{
				execve(splited[j])
				printf("%s\n", splited[j++]);
			}
		}
		i++;
	}
	return (0);
}