/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:00:05 by aelsayed          #+#    #+#             */
/*   Updated: 2025/04/20 09:52:56 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list    *ft_arr2list(char **arr)
{
    t_list    *list = NULL;
    t_list    *new;

    if (!arr)
        return (NULL);
    while (*arr)
    {
        new = ft_lstnew(ft_strdup(*arr));
        if (!new)
        {
            ft_lstclear(&list, free);
            return (NULL);
        }
        ft_lstadd_back(&list, new);
        arr++;
    }
    return (list);
}

// int	unset_variable(char *key, t_shell *vars)
// {
// 	char	*c;
// 	t_list	*new;

// 	new = NULL;
// 	vars->tmp = ft_arr2list(vars->envp);
// 	ft_free("2", vars->envp);
// 	while (vars->tmp)
// 	{
// 		c = (char *)vars->tmp->content;
// 		if (ft_strncmp(c, key, ft_strlen(key)) == 0 && c[ft_strlen(key)] == '=')
// 		{
// 			vars->tmp = vars->tmp->next;
// 			continue;
// 		}
// 		ft_lstadd_back(&new, vars->tmp);
// 		vars->tmp = vars->tmp->next;
// 	}
// 	ft_lstclear(&vars->tmp, free);
// 	vars->envp = ft_list2arr(new);
// 	return (TRUE);
// }

int	unset_variable(char *key, t_shell *vars)
{
	t_list	*curr;
	t_list	*next;
	char	*content;
	t_list	*new_env;

	new_env = NULL;
	curr = ft_arr2list(vars->envp);
	ft_free("2", vars->envp);
	while (curr)
	{
		next = curr->next;
		content = (char *)curr->content;
		if (ft_strncmp(content, key, ft_strlen(key)) == 0 && content[ft_strlen(key)] == '=')
			ft_free("11", content, curr);
		else
		{
			curr->next = NULL;
			ft_lstadd_back(&new_env, curr);
		}
		curr = next;
		printf("-\n");
	}
	vars->envp = ft_list2arr(new_env);
	return (TRUE);
}


int	unset(int ac, char **av, t_shell *vars)
{
	int	i;

	i = 1;
	while (av[i])
	{
		unset_variable(av[i], vars);
		i++;
	}
	return (TRUE);
}
int main (int ac, char **av, char **envp)
{
	t_shell vars;
	vars.envp = ft_arrdup(envp);
	unset(ac, av, &vars);
	env(1, av, &vars);
	return (0);
}
