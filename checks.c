/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:57:10 by yoelansa          #+#    #+#             */
/*   Updated: 2023/05/23 16:11:20 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_name(char *str)
{
	int i;

	i = ft_strlen(str) - 1;
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

void	_check_chars(char *s, t_ec *ec, int i, int p)
{
	while (s[i])
	{
		if (s[0] == '\n' || (s[i] == '\n' && s[i + 1] && s[i + 1] == '\n'))
		{
			write(1, "map's not rectangle\n", 20);
			exit(1);
		}
		if (s[i] != '1' && s[i] != '\n' && s[i] != 'E' && s[i] != '0' && s[i] != 'C' && s[i] != 'P')
		{
			write(1, "some charachters are not matching the ones should be\n", 53);
			break;
			exit(1);
		}
		if (s[i] == 'E')
			ec->e++;
		if (s[i] == 'P')
			p++;
		if (s[i] == 'C')
			ec->c++;
		i++;
	}
	if (ec->e != 1 || p != 1 || ec->c == 0)
	{
		write(1, "Chars Error\n", 12);
		exit(1);
	}
}

void	check_chars(char *s, t_ec *ec)
{
	int	i;
	int	p;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] == '\n')
	{
		write(1, "map's not rectangle\n", 20);
		exit(1);
	}
	i = 0;
	p = 0;
	_check_chars(s, ec, i, p);
}

void	wall_error(void)
{
	write(1, "Wall Error\n", 11);
	exit(1);
}
void	check_walls(char **map)
{
	int y = 0;
	int i = 0;

	while (map[y][i])
	{
		if (map[y][i] != '1')
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

void	check_path(char **map, int j, int i, t_ec *ec)
{
	if (map[j][i] == '1')
		return;
	else if (map[j][i] == 'E')
	{
		ec->e++;
		map[j][i] = '1';
		return;
	}
	else if (map[j][i] == 'C')
		ec->c++;
	map[j][i] = '1';
	check_path(map, j, i + 1, ec);
	check_path(map, j + 1, i, ec);
	check_path(map, j, i - 1, ec);
	check_path(map, j - 1, i, ec);
}