/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:04:41 by ahakki            #+#    #+#             */
/*   Updated: 2025/04/20 15:37:38 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*expand(char *str, char *var, int i)
{
	char	*new;
	int		len;
	int		j;
	int		k;

	ft_init(2, &j, &k);
	len = ft_strlen(str) + ft_strlen(var);
	new = (char *)malloc(sizeof(char) * (len + 1));
	while (j < i)
	{
		new[j] = str[j];
		j++;
	}
	while (var && var[k])
	{
		new[j] = var[k];
		j++;
		k++;
	}
	while (str[i])
	{
		new[j] = str[i];
		j++;
		i++;
	}
	new[j] = '\0';
	return (free(str), new);
}


