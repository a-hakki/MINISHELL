/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kharba9_tatsda9.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:58:10 by ahakki            #+#    #+#             */
/*   Updated: 2025/03/03 22:43:06 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_char(char *str, char c)
{
	int	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

char	*removequotes(char *str, char quote)
{
	char	*result;

	int (i), (j), (len);
	if (!str || !(*str))
		return (NULL);
	if (count_char(str, quote) == 0)
		return (str);
	len = ft_strlen(str);
	result = malloc(len + 1);
	if (!result)
		return (free(str), NULL);
	ft_init(2, &i, &j);
	while (str[i])
	{
		if (str[i] == quote && str[i + 1] == quote)
		{
			i += 2;
			continue;
		}
		result[j++] = str[i++];
	}
	while (j <= len)
		result[j++] = '\0';
	free(str);
	return (result);
}



