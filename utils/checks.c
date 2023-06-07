/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:57:10 by yoelansa          #+#    #+#             */
/*   Updated: 2023/06/07 00:36:27 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	check_name(char *str)
{
	int	i;

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
		_exit(5);
}

void	_check_chars(char *s, t_ec *ec, int i, int p)
{
	while (s[i])
	{
		if (s[0] == '\n' || (s[i] == '\n' && s[i + 1] && s[i + 1] == '\n'))
			_exit(2);
		if (s[i] != '1' && s[i] != '\n' && s[i] != 'E'
			&& s[i] != '0' && s[i] != 'C' && s[i] != 'P')
			_exit(6);
		if (s[i] == 'E')
			ec->e++;
		if (s[i] == 'P')
			p++;
		if (s[i] == 'C')
			ec->c++;
		i++;
	}
	if (ec->e != 1 || p != 1 || ec->c == 0)
		_exit(4);
}

void	check_chars(char *s, t_ec *ec)
{
	int	i;
	int	p;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] == '\n')
		_exit(2);
	i = 0;
	p = 0;
	_check_chars(s, ec, i, p);
}

void	wall_error(void)
{
	write(1, "Wall Error\n", 11);
	exit(1);
}

void	check_walls(char **map, int i, int y)
{
	while (map[y][++i])
	{
		if (map[y][i] != '1')
			wall_error();
	}
	while (map[++y])
	{
		if (map[y][0] != '1')
			wall_error();
	}
	y = -1;
	while (map[++y])
	{
		if (map[y][i - 1] != '1')
			wall_error();
	}
	i = -1;
	while (map[y - 1][++i])
	{
		if (map[y - 1][i] != '1')
			wall_error();
	}
}
