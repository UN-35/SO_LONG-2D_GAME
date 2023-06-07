/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys__textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:19:11 by yoelansa          #+#    #+#             */
/*   Updated: 2023/06/07 00:36:20 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	key_press(int keycode, void *args)
{
	t_mlx	*data;

	data = (t_mlx *)args;
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
	return (0);
}

int	key_release(int keycode, void *args)
{
	t_mlx	*data;

	data = (t_mlx *)args;
	if (keycode == UP)
		data->keys.up = 0;
	else if (keycode == DOWN)
		data->keys.down = 0;
	else if (keycode == RIGHT)
		data->keys.right = 0;
	else if (keycode == LEFT)
		data->keys.left = 0;
	return (0);
}

void	get_image(t_mlx *args)
{
	int	dm;

	dm = 64;
	args->wall = mlx_xpm_file_to_image(args->mlx,
			"textures/wall_1_.xpm", &dm, &dm);
	args->exit = mlx_xpm_file_to_image(args->mlx,
			"textures/exit1.xpm", &dm, &dm);
	args->floor = mlx_xpm_file_to_image(args->mlx,
			"textures/floor1_1_.xpm", &dm, &dm);
	args->player = mlx_xpm_file_to_image(args->mlx,
			"textures/pngegg.xpm", &dm, &dm);
	args->coins = mlx_xpm_file_to_image(args->mlx,
			"textures/pngegg_1_.xpm", &dm, &dm);
}

void	display_util(t_mlx *args, int i, int j)
{
	if (args->map[i][j] == '0' || args->map[i][j] == 'E'
		|| args->map[i][j] == 'P' || args->map[i][j] == 'C')
		mlx_put_image_to_window(args->mlx,
			args->wind, args->floor, j * 50, i * 50);
	if (args->map[i][j] == 'E')
		mlx_put_image_to_window(args->mlx,
			args->wind, args->exit, j * 50, i * 50);
	if (args->map[i][j] == 'P')
		mlx_put_image_to_window(args->mlx,
			args->wind, args->player, j * 50, i * 50);
	if (args->map[i][j] == 'C')
		mlx_put_image_to_window(args->mlx,
			args->wind, args->coins, j * 50, i * 50);
	else if (args->map[i][j] == '1')
		mlx_put_image_to_window(args->mlx,
			args->wind, args->wall, j * 50, i * 50);
}

int	display(void *data)
{
	t_mlx	*args;
	int		i;
	int		j;

	args = (t_mlx *)data;
	get_image(args);
	update_player(args);
	i = 0;
	while (args->map[i])
	{
		j = 0;
		while (args->map[i][j])
		{
			display_util(args, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
