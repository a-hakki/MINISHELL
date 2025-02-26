/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:41:55 by ahakki            #+#    #+#             */
/*   Updated: 2025/02/26 14:57:23 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*strquotes(char *str)
{
	static char	*next_token;
	char		*start;
	char		q;
	int			i;

	q = 0;
	i = 0;
	if (str)
		next_token = str;
	if (!next_token || !*next_token)
		return (NULL);
	while (*next_token && *next_token != '\'' && *next_token != '\"')
		next_token++;
	if (*next_token == '\'' || *next_token == '\"')
		q = *next_token++;
	while (next_token[i] && next_token[i] != q)
		i++;
	if ((*next_token + i )!= q || (*next_token + i) == '\0')
		return (printf("error\n"), NULL);
	return (ft_strndup(next_token, i));
}

int	main(int	ac, char **av)
{
	if (ac > 1)
	{
		char *str = strquotes(av[1]);
		while (str)
		{
			printf("%s\n", str);
			str = strquotes(av[1]);
		}
	}
}