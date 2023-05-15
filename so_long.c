/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:20:03 by yoelansa          #+#    #+#             */
/*   Updated: 2023/05/15 23:28:44 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void check_name(char *str)
{
	int i = ft_strlen(str) - 1;
	if (str[i] == 'r')
		i--;
	if (str[i] == 'e')
		i--;
	if (str[i] == 'b')
		i--;
	if (str[i] == '.')
		i--;
	if (i != (int)(ft_strlen(str) - 5))
	{
		write(1, "wrong map name", 15);
		exit (1);
	}
}

char *read_(int fd)
{
	char *str = malloc(sizeof(char) + 1);
	char *content = NULL;
	int i = 1;
	while (i > 0)
	{
		i = read(fd, str, 1);
		str[i] = '\0';
		content = ft_strjoin(content, str);
	}
	free(str);
	return (content);
}

void	check_chars(char *s)
{
	int i;
	int j;
	int k;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] == '\n')
	{
		write(1, "map's not rectangle\n", 20);
		exit(1);
	}
	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != '\n' && s[i] != 'E' && s[i] != '0' && s[i] != 'C' && s[i] != 'P')
		{
			write(1, "some charachters are not matching the ones should be\n", 53);
			break;
		}
		if (s[i] == 'E')
			j++;
		if (s[i] == 'P')
			k++;
		i++;
	}
	if (j == 0 || j > 1)
		write(1, "Exit error\n", 11);
	if (k == 0 || k > 1)
		write(1, "Player error\n", 13);
}

void	wall_error(void)
{
	write(1, "Wall Error\n", 11);
	exit(1);
}

void	check_walls(char **map)
{
	int y = 1;
	int i = 0;
	
	while (map[0][i])
	{
		if (map[0][i] != '1')
			wall_error();
		i++;
	}
	while (map[y])
	{
		if (map[y][0] != '1')
			wall_error();
		y++;
	}
	y = 0;
	while (map[y])
	{
		if (map[y][i - 1] != '1')
			wall_error();
		y++;
	}
	i = 0;
	while (map[y - 1][i])
	{
		if (map[y - 1][i] != '1')
			wall_error();
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	check_name(av[1]);
	int fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "open fail", 10);
		return(1);
	}
	char *content = NULL;
	char **map;
	content = read_(fd);

	check_chars(content);
	map = ft_split(content, '\n');
	if (!map)
		return(0);
	check_walls(map);
	int i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]) && map[i + 1])
		{
			write(1, "map's not rectangle\n", 20);
			return (1);
		}
		i++;
	}
	return (0);
}