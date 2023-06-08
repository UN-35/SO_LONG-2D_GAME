/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:20:03 by yoelansa          #+#    #+#             */
/*   Updated: 2023/06/08 00:41:57 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*find_p(char **map)
{
	int	i;
	int	j;
	int	*k;

	i = 0;
	j = 0;
	k = malloc(2 * sizeof(int));
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				k[0] = i;
				k[1] = j;
				return (k);
			}
			i++;
		}
		j++;
	}
	return (0);
}

void	check_path(char **map, int j, int i, t_ec *ec)
{
	if (map[j][i] == '1')
		return ;
	else if (map[j][i] == 'E')
	{
		ec->e++;
		map[j][i] = '1';
		return ;
	}
	else if (map[j][i] == 'C')
		ec->c++;
	map[j][i] = '1';
	check_path(map, j, i + 1, ec);
	check_path(map, j + 1, i, ec);
	check_path(map, j, i - 1, ec);
	check_path(map, j - 1, i, ec);
}

void	_mlx(t_mlx	vars, t_ec *ec1)
{
	vars.mlx = mlx_init();
	vars.wind = mlx_new_window(vars.mlx, 50 * ft_strlen(vars.map[0]),
			50 * tab_size(vars.map), "IM SONIC MAN!!");
	mlx_hook(vars.wind, 17, 0, _close, &vars);
	vars.keys.up = 0;
	vars.keys.down = 0;
	vars.keys.left = 0;
	vars.keys.right = 0;
	vars.count = 1;
	vars.ec = ec1;
	mlx_loop_hook(vars.mlx, display, &vars);
	mlx_hook(vars.wind, 2, 0, key_press, &vars);
	mlx_hook(vars.wind, 3, 0, key_release, &vars);
	mlx_loop(vars.mlx);
}

void	_cont(t_mlx vars, char *content)
{
	int		*k;
	t_ec	*ec;
	t_ec	*ec1;
	char	**new_map;

	k = find_p(vars.map);
	ec = malloc(sizeof(t_ec));
	ec->e = 0;
	ec->c = 0;
	ec1 = malloc(sizeof(t_ec));
	ec1->e = 0;
	ec1->c = 0;
	check_chars(content, ec1);
	check_walls(vars.map, 0, 0);
	new_map = array_dup(vars.map);
	check_path(new_map, k[1], k[0], ec);
	if (ec->e != ec1->e || ec->c != ec1->c)
		_exit(3);
	_mlx(vars, ec1);
}

int	main(int ac, char **av)
{
	int		i;
	int		fd;
	char	*content;
	t_mlx	vars;

	if (ac != 2)
		return (1);
	check_name(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		_exit(1);
	content = read_(fd);
	vars.map = ft_split(content, '\n');
	if (!vars.map)
		return (0);
	i = -1;
	while (vars.map[++i])
	{
		if (ft_strlen(vars.map[i])
			!= ft_strlen(vars.map[i + 1]) && vars.map[i + 1])
			_exit(2);
	}
	_cont(vars, content);
}
