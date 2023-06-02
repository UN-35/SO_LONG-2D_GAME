/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:20:03 by yoelansa          #+#    #+#             */
/*   Updated: 2023/05/31 12:54:45 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int	*find_p(char **map)
{
	int i = 0;
	int j = 0;
	int *k;
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
				return(k);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int tab_size(char **map)
{
	int i = 0;
	while (map[i])
		i++;
	return (i);
}

int _close(void *args)
{
	(void)args;
	exit(0);
}

int key_press(int keycode, void *args)
{
	t_mlx *data;
	
	data = (t_mlx*)args;
	if (keycode == 53)
		exit(0);
	else if (keycode == UP)
		data->keys.up = 1;
	else if (keycode == DOWN)
		data->keys.down = 1;
	else if (keycode == RIGHT)
		data->keys.right = 1;
	else if (keycode == LEFT)
		data->keys.left = 1;
	return 0;
}


int key_release(int keycode, void *args) {
	t_mlx *data;

	data = (t_mlx*)args;
	if (keycode == UP)
		data->keys.up = 0;
	else if (keycode == DOWN)
		data->keys.down = 0;
	else if (keycode == RIGHT)
		data->keys.right = 0;
	else if (keycode == LEFT)
		data->keys.left = 0;
	return 0;
}

void	get_image(t_mlx *args)
{
	int	dm = 64;
	args->wall = mlx_xpm_file_to_image(args->mlx, "textures/wall_1_.xpm", &dm, &dm);
	args->exit = mlx_xpm_file_to_image(args->mlx, "textures/exit1.xpm", &dm, &dm);
	args->floor = mlx_xpm_file_to_image(args->mlx, "textures/floor1_1_.xpm", &dm, &dm);
	args->player = mlx_xpm_file_to_image(args->mlx, "textures/pngegg.xpm", &dm, &dm);
	args->coins = mlx_xpm_file_to_image(args->mlx, "textures/pngegg_1_.xpm", &dm, &dm);
}


int display(void *data)
{
	t_mlx *args;
	args = (t_mlx*)data;
	get_image(args);
	update_player(args);
	int i = 0;
	while (args->map[i])
	{
		int j = 0;
		while (args->map[i][j])
		{
			if (args->map[i][j] == '1')
				mlx_put_image_to_window(args->mlx, args->wind, args->wall, j * 50, i * 50);
			else if (args->map[i][j] == 'E')
				mlx_put_image_to_window(args->mlx, args->wind, args->exit, j * 50, i * 50);
			else if (args->map[i][j] == '0')
				mlx_put_image_to_window(args->mlx, args->wind, args->floor, j * 50, i * 50);
			else if (args->map[i][j] == 'P')
				mlx_put_image_to_window(args->mlx, args->wind, args->player, j * 50, i * 50);
			else if (args->map[i][j] == 'C')
				mlx_put_image_to_window(args->mlx, args->wind, args->coins, j * 50, i * 50);
			j++;
		}
		i++;
	}
	return (0);
}

char **array_dup(char **map)
{
	char **new_map;
	new_map = malloc(tab_size(map) * sizeof(char*) + 1);
	int i = 0;
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	_mlx(t_mlx	vars, t_ec *ec1)
{
	vars.mlx = mlx_init();
	vars.wind = mlx_new_window(vars.mlx, 50 * ft_strlen(vars.map[0]), 50 * tab_size(vars.map), "I'm sonic bitch!");
	mlx_hook(vars.wind, 17, 0, _close, &vars);// close program by closing the window
	vars.keys.up = 0;
	vars.keys.down = 0;
	vars.keys.left = 0;
	vars.keys.right = 0;
	vars.ec = ec1;
	mlx_loop_hook(vars.mlx, display, &vars);
	mlx_hook(vars.wind, 2, 0, key_press, &vars);// on key press 
	mlx_hook(vars.wind, 3, 0, key_release, &vars); // on key release
	mlx_loop(vars.mlx);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	check_name(av[1]);
	int fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "open fail\n", 10);
		exit(1);
	}
	char *content = NULL;
	t_mlx vars;
	content = read_(fd);
	vars.map = ft_split(content, '\n');
	if (!vars.map)
		return(0);
	int i = 0;
	while (vars.map[i])
	{
		if (ft_strlen(vars.map[i]) != ft_strlen(vars.map[i + 1]) && vars.map[i + 1])
		{
			write(1, "map's not rectangle\n", 20);
			exit(1);
		}
		i++;
	}

	int *k = find_p(vars.map);
	t_ec *ec = malloc(sizeof(t_ec));
	ec->e = 0;
	ec->c = 0;
	t_ec *ec1 = malloc(sizeof(t_ec));
	ec1->e = 0;
	ec1->c = 0;
	check_chars(content, ec1);
	check_walls(vars.map);
	char **new_map = array_dup(vars.map);
	check_path(new_map, k[1], k[0], ec);
	/// free the new_map;
	if (ec->e != ec1->e || ec->c != ec1->c)
	{
		write(1, "invalid path\n", 14);
		exit(1);
	}
	_mlx(vars, ec1);
	return (0);
}