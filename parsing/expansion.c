/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:35:39 by aelsayed          #+#    #+#             */
/*   Updated: 2025/05/10 18:07:06 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_var_len(char *str)
{
	int	i;

	i = 0;
	if (!str || !(ft_isalpha(str[0]) || str[0] == '_'))
		return (0);
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (i);
}

int	add_value(t_shell *vars, t_list **s, char *str, int q)
{
	char	*var_name;
	char	*var_value;
	t_list	*last;

	var_value = NULL;
	var_name = NULL;
	if (*str == '$' && ft_strchr("'\"", *(str + 1)) && !q)
		return (1);
	if (*str == '$' && *(str + 1) == '?')
		var_value = ft_itoa(vars->exit);
	else if (get_var_len(str + 1) == 0)
		return (ft_lstadd_back(s, ft_lstnew(ft_strdup("$"))), 1);
	if (!var_value)
	{
		var_name = ft_strndup(str + 1, get_var_len(str + 1));
		var_value = ft_strdup(get_env(var_name, vars));
	}
	last = ft_lstlast(*s);
	if (last)
		last->next = ft_str_to_lst(var_value, 1);
	else
		*s = ft_str_to_lst(var_value, 1);
	return (ft_free("11", var_name, var_value), \
		get_var_len(str + 1) + 1 + (*str == '$' && str[1] == '?'));
}

int	add_char(t_list **s, char c)
{
	t_list	*new;

	new = ft_lstnew(ft_strndup(&c, 1));
	new->type = 0;
	ft_lstadd_back(s, new);
	return (1);
}

void	handle_single_quotes(t_list **s, int *i, char *str)
{
	(*i) += add_char(s, '\'');
	while (str[*i] && str[*i] != '\'')
		*i += add_char(s, str[*i]);
	if (str[*i] == '\'')
		*i += add_char(s, '\'');
}
int	canbexpanded(char *str)
{
	char	cmd[256];
	int		i = 0;

	while (str[i] && str[i] != ' ')
	{
		cmd[i] = str[i];
		i++;
	}
	cmd[i] = '\0';
	if (!ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "unset"))
		return (printf("should not be expanded\n"), 0);
	return (1);
}


void	expand(t_shell *vars, char **str, char ***arr)
{
	int 	i;
	int		q;
	t_list	*s;

	s = NULL;
	ft_init(2, &i, &q);
	while ((*str)[i])
	{
		if ((*str)[i] == '"')
		{
			q = !q;
			i += add_char(&s, (*str)[i]);
		}
		else if ((*str)[i] == '\'' && !q)
			handle_single_quotes(&s, &i, *str);
		else if ((*str)[i] == '$')
			i += add_value(vars, &s, &(*str)[i], q);
		// else if ((*str)[i] == '*' && canbexpanded(*str) && !q && i++)
		// 	i += expandwildcard(&s);
		else
			i += add_char(&s, (*str)[i]);
	}
	ft_free("12", *str, *arr);
	*str = ft_lst2str(s);
	*arr = split_list(s, ' ');
	ft_lstclear(&s, free);
}
