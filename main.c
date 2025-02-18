/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:10:45 by ahakki            #+#    #+#             */
/*   Updated: 2025/02/18 09:38:55 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

char	*ft_strjoin_with_slash(const char *s1, const char *s2)
{
	char	*new_str;
	int		i, j;

	if (!s1 || !s2)
		return (NULL);
	new_str = malloc(strlen(s1) + strlen(s2) + 2);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i++] = '/';
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}

void    sigint_handler(int sig)
{
    (void)sig;
    write(1, "\nminishell> ", 12);
    rl_replace_line("", 1);
}

void	foo(int sig)
{
	(void)sig;
	kill(0, -9);
}

int main(int ac, char **av, char **env)
{
    char    *input;
    char    **args;
    char    **paths;
    char    *cmd_path;
    int     i;
    int     pid;

    (void)ac;
    (void)av;
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, foo);
    while (1)
    {
        input = readline("minishell> ");
        if (!input)
            break;
        if (*input)
        {
            add_history(input);
            args = ft_split(input, ' ');
            if (!args)
            {
                perror("Memory allocation failed");
                free(input);
            }
            i = 0;
            paths = NULL;
            while (env[i])
            {
                if (!strncmp(env[i], "PATH=", 5))
                {
                    paths = ft_split(env[i] + 5, ':');
                    break;
                }
                i++;
            }
            if (!paths)
            {
                perror("PATH variable not found");
                ft_free("2", args);
                free(input);
                continue;
            }
            pid = fork();
            if (pid == 0)
            {
                i = 0;
                while (paths[i])
                {
                    cmd_path = ft_strjoin_with_slash(paths[i], args[0]);
                    execve(cmd_path, args, env);
                    free(cmd_path);
                    i++;
                }
                perror("Command not found");
                exit(127);
            }
            else if (pid > 0)
                wait(NULL);
            else
                perror("Fork failed");
            ft_free("2", args);
            ft_free("2", paths);
        }
        free(input);
    }
    clear_history();
    return (0);
}

