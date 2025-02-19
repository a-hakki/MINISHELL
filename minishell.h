/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:18:16 by aelsayed          #+#    #+#             */
/*   Updated: 2025/02/19 13:49:28 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "signal.h"
# include <readline/readline.h>
# include <readline/history.h>


typedef struct s_check
{
    char        dquot;
    char        squot;
    char        rpar;
    char        par;
    char        special;
    char        fpar;
    char        lpar;
}            t_check;


typedef struct s_shell
{
    char        **envp;
    char        *cmd;
	t_list	    *args;
	t_list      *tmp;
    t_check     check;
}            t_shell;


#endif