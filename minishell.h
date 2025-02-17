/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:11:01 by ahakki            #+#    #+#             */
/*   Updated: 2025/02/17 13:48:08 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"

typedef struct s_node
{
    char *head;
    char *left;
    char *operation;
    char *right;
    struct s_node *child;
} t_node;

#endif