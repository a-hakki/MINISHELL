/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:41:55 by ahakki            #+#    #+#             */
/*   Updated: 2025/02/26 10:09:56 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	strquotes(char *str)
{
	static char	*next_token;
	char		*start;
	char		q;

	if (str)
		next_token = str;
	if (!next_token || !*next_token)
		return ;
	while (*next_token != '\'' || *next_token != '\"')
		next_token++;
	if (*next_token == '\'' || *next_token == '\"')
		q = *next_token++;
	while (*next_token && *next_token != q)
		printf("%c", *next_token);
	printf("\n");
	if (*next_token != q)
		printf("error\n");
}

int	main(int	ac, char **av)
{
	
}