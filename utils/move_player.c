/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:30:14 by yoelansa          #+#    #+#             */
/*   Updated: 2023/06/08 00:49:26 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	move_up(t_mlx *args, int dir, int *p, char *str)
{
	str = ft_itoa(args->count);
	p = find_p(args->map);
	if (dir == 1)
	{
		if ((args->map[p[1] - 1][p[0]] == '0')
			|| (args->map[p[1] - 1][p[0]] == 'C'))
		{
			ft_putstr(str);
			write(1, "\n", 1);
			free(str);
			args->count++;
		}
		if (args->map[p[1] - 1][p[0]] == '0')
			ft_swap(&args->map[p[1] - 1][p[0]], &args->map[p[1]][p[0]]);
		else if (args->map[p[1] - 1][p[0]] == 'C')
		{
			args->map[p[1] - 1][p[0]] = '0';
			ft_swap(&args->map[p[1] - 1][p[0]], &args->map[p[1]][p[0]]);
			args->ec->c--;
		}
		else if (args->map[p[1] - 1][p[0]] == 'E' && args->ec->c == 0)
			exit(0);
	}
	free(p);
}

void	move_down(t_mlx *args, int dir, int *p, char *str)
{
	str = ft_itoa(args->count);
	p = find_p(args->map);
	if (dir == 2)
	{
		if ((args->map[p[1] + 1][p[0]] == '0')
			|| (args->map[p[1] + 1][p[0]] == 'C'))
		{
			ft_putstr(str);
			write(1, "\n", 1);
			args->count++;
			free(str);
		}
		if (args->map[p[1] + 1][p[0]] == '0')
			ft_swap(&args->map[p[1] + 1][p[0]], &args->map[p[1]][p[0]]);
		else if (args->map[p[1] + 1][p[0]] == 'C')
		{
			args->map[p[1] + 1][p[0]] = '0';
			ft_swap(&args->map[p[1] + 1][p[0]], &args->map[p[1]][p[0]]);
			args->ec->c--;
		}
		else if (args->map[p[1] + 1][p[0]] == 'E' && args->ec->c == 0)
			exit(0);
	}
	free(p);
}

void	move_left(t_mlx *args, int dir, int *p, char *str)
{
	str = ft_itoa(args->count);
	p = find_p(args->map);
	if (dir == 3)
	{
		if ((args->map[p[1]][p[0] - 1] == '0')
			|| (args->map[p[1]][p[0] - 1] == 'C'))
		{
			ft_putstr(str);
			write(1, "\n", 1);
			args->count++;
			free(str);
		}
		if (args->map[p[1]][p[0] - 1] == '0')
			ft_swap(&args->map[p[1]][p[0] - 1], &args->map[p[1]][p[0]]);
		else if (args->map[p[1]][p[0] - 1] == 'C')
		{
			args->map[p[1]][p[0] - 1] = '0';
			ft_swap(&args->map[p[1]][p[0] - 1], &args->map[p[1]][p[0]]);
			args->ec->c--;
		}
		else if (args->map[p[1]][p[0] - 1] == 'E' && args->ec->c == 0)
			exit(0);
	}
	free(p);
}

void	move_right(t_mlx *args, int dir, int *p, char *str)
{
	str = ft_itoa(args->count);
	p = find_p(args->map);
	if (dir == 4)
	{
		if ((args->map[p[1]][p[0] + 1] == '0')
			|| (args->map[p[1]][p[0] + 1] == 'C'))
		{
			ft_putstr(str);
			write(1, "\n", 1);
			args->count++;
			free(str);
		}
		if (args->map[p[1]][p[0] + 1] == '0')
			ft_swap(&args->map[p[1]][p[0] + 1], &args->map[p[1]][p[0]]);
		else if (args->map[p[1]][p[0] + 1] == 'C')
		{
			args->map[p[1]][p[0] + 1] = '0';
			ft_swap(&args->map[p[1]][p[0] + 1], &args->map[p[1]][p[0]]);
			args->ec->c--;
		}
		else if (args->map[p[1]][p[0] + 1] == 'E' && args->ec->c == 0)
			exit(0);
	}
	free(p);
}

void	update_player(t_mlx *args)
{
	static int	i;

	i++;
	if (i % 2)
		return ;
	if (args->keys.up)
		move_up(args, 1, NULL, NULL);
	if (args->keys.down)
		move_down(args, 2, NULL, NULL);
	if (args->keys.left)
		move_left(args, 3, NULL, NULL);
	if (args->keys.right)
		move_right(args, 4, NULL, NULL);
}
