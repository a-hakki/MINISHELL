/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:23:41 by aelsayed          #+#    #+#             */
/*   Updated: 2025/04/08 16:30:04 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_array(char **arr)
{
	int (i) = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		printf("words %d : %s\n", i, arr[i]);
		i++;
	}
}
