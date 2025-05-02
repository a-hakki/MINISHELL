/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:59:00 by ahakki            #+#    #+#             */
/*   Updated: 2025/05/02 19:33:40 by ahakki           ###   ########.fr       */
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
	char **matches = malloc(sizeof(char *) * (MAX_MATCHES + 1));
	int count = 0;

	if (!matches)
		return NULL;

	dir = opendir(".");
	if (!dir)
		return (free(matches), NULL);

	while ((entry = readdir(dir)) != NULL)
	{
		if (match_pattern(pattern, entry->d_name))
		{
			if (count < MAX_MATCHES)
			{
				matches[count] = ft_strdup(entry->d_name);
				count++;
			}
			else
				break;
		}
	}
	matches[count] = NULL;
	closedir(dir);
	return matches;
}

int	main()
{
	char **matches;

	matches = wildcard_match("t*");
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
