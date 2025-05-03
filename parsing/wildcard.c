/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:59:00 by ahakki            #+#    #+#             */
/*   Updated: 2025/05/02 20:20:00 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	match_pattern(const char *pattern, const char *filename)
{
	int	i;

	i = 0;
	while (pattern[i] && pattern[i] != '*')
	{
		if (pattern[i] != filename[i])
			return (0);
		i++;
	}
	if (pattern[i] == '*')
		return (1);
	return (pattern[i] == '\0' && filename[i] == '\0');
}

char	**wildcard_match(const char *pattern)
{
	DIR *dir;
	struct dirent *entry;
	char **matches;
	int count;

	count = 0;
	matches = malloc(sizeof(char *) * (MAX_MATCHES + 1));
	dir = opendir(".");
	if (!matches || !dir)
		return (ft_free("1", matches), NULL);
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] == '.')
			continue;
		if (match_pattern(pattern, entry->d_name))
		{
			if (count < MAX_MATCHES)
				matches[count++] = ft_strdup(entry->d_name);
			else
				break;
		}
	}
	matches[count] = NULL;
	return (closedir(dir), matches);
}


int	main()
{
	char **matches;

	matches = wildcard_match("*");
	if (matches)
	{
		int i = 0;
		while (matches[i] != NULL)
		{
			printf("Match: %s\n", matches[i]);
			i++;
		}
		ft_free("2",matches);
	}
	else
		printf("No matches found or an error occurred.\n");
	return 0;
}
