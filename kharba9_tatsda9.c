/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kharba9_tatsda9.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:58:10 by ahakki            #+#    #+#             */
/*   Updated: 2025/03/07 19:51:27 by ahakki           ###   ########.fr       */
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

char	*removequotes(char *str)
{
	char	*result;

	int (i), (j), (len), (c);
	if (!str || !(*str))
		return (NULL);
	if (count_char(str, '\'') == 0 && count_char(str, '"') == 0)
		return (str);
	len = ft_strlen(str);
	result = malloc(len + 1);
	if (!result)
		return (free(str), NULL);
	ft_init(3, &i, &j, &c);
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '"') && c == 0)
			c = str[i++];
		else if (str[i] == c)
		{
			c = 0;
			i++;
		}
		else
			result[j++] = str[i++];
	}
	result[j] = '\0';
	return (result);
}

int main(void)
{
	printf("%s", removequotes("\"hchsv\"'\"'\"ugc\""));
}
