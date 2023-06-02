/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:30:14 by yoelansa          #+#    #+#             */
/*   Updated: 2023/05/28 20:33:36 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move_up(t_mlx *args, int dir)
{
	int	*p;

	p = find_p(args->map);
	if (dir == 1)
	{
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

void	move_down(t_mlx *args, int dir)
{
	int	*p;

	p = find_p(args->map);
	if (dir == 2)
	{
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

void	move_left(t_mlx *args, int dir)
{
	int	*p;

	p = find_p(args->map);
	if (dir == 3)
	{
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

void	move_right(t_mlx *args, int dir)
{
	int	*p;

	p = find_p(args->map);
	if (dir == 4)
	{
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



//------------------------
void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}
void	update_player(t_mlx *args)
{
	static int	i;
	static int	c;

	i++;
	if (i % 5)
		return ;
	if (args->keys.up)
		move_up(args, 1);
	if (args->keys.down)
		move_down(args, 2);
	if (args->keys.left)
		move_left(args, 3);
	if (args->keys.right)
		move_right(args, 4);
	if ((args->keys.up || args->keys.down || args->keys.left || args->keys.right))
	{
		char	*str;

		str = ft_itoa(c);
		ft_putstr(str);
		write(1, "\n", 1);
		c++;
		free(str);
	}
}
