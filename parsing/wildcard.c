/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:59:00 by ahakki            #+#    #+#             */
/*   Updated: 2025/05/03 22:11:06 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	match_pattern(const char *pattern, const char *str)
{
	if (!pattern || !str)
		return (0);
	while (*pattern)
	{
		if (*pattern == '*')
		{
			pattern++;
			if (!*pattern)
				return (1);
			while (*str)
			{
				if (match_pattern(pattern, str))
					return (1);
				str++;
			}
			return (0);
		}
		if (*pattern != *str)
			return (0);
		pattern++;
		str++;
	}
	return (*str == '\0');
}

int	ft_hssab(void)
{
	DIR				*dir;
	struct dirent	*e;
	int				i;

	i = 0;
	dir = opendir(".");
	e = readdir(dir);
	while (e != NULL)
	{
		i++;
		e = readdir(dir);
	}
	return (closedir(dir), i);
}

char	**wildcard_match(const char *p)
{
	DIR				*dir;
	struct dirent	*e;
	char			**matches;
	int				count;

	count = 0;
	matches = malloc(sizeof(char *) * (ft_hssab() + 1));
	dir = opendir(".");
	if (!matches || !dir)
		return (ft_free("1", matches), NULL);
	e = readdir(dir);
	while (e != NULL)
	{
		if (((e->d_name[0] != '.' && p[0] != '.') || (e->d_name[0] == '.' \
			&& p[0] == '.'))  && match_pattern(p, e->d_name))
				matches[count++] = ft_strdup(e->d_name);
		e = readdir(dir);
	}
	matches[count] = NULL;
	return (closedir(dir), matches);
}

int	main(int ac, char **av)
{
	char	**matches;
	int		i;

	i = 0;
	if (ac == 1)
		return (0);
	matches = wildcard_match(av[1]);
	if (matches)
	{
		while (matches[i] != NULL)
		{
			printf("Match: %s\n", matches[i]);
			i++;
		}
		ft_free("2", matches);
	}
	return (0);
}
