/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:54:43 by yoelansa          #+#    #+#             */
/*   Updated: 2023/06/07 00:36:12 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*read_(int fd)
{
	char	*str;
	char	*content;
	int		i;

	str = malloc(sizeof(char) + 1);
	content = NULL;
	i = 1;
	while (i > 0)
	{
		i = read(fd, str, 1);
		str[i] = '\0';
		content = ft_strjoin(content, str);
	}
	free(str);
	return (content);
}

int	tab_size(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	_close(void *args)
{
	(void)args;
	exit(0);
}

char	**array_dup(char **map)
{
	char	**new_map;
	int		i;

	new_map = malloc(tab_size(map) * sizeof(char *) + 1);
	i = 0;
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	_exit(int i)
{
	if (i == 1)
		write(1, "open fail\n", 10);
	else if (i == 2)
		write(1, "map's not rectangle\n", 20);
	else if (i == 3)
		write(1, "invalid path\n", 14);
	else if (i == 4)
		write(1, "Chars Error\n", 12);
	else if (i == 5)
		write(1, "wrong map name", 15);
	else if (i == 6)
		write(1, "some charachters are not matching the ones should be\n", 53);
	exit(1);
}
