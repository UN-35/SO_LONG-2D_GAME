/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:27:05 by yoelansa          #+#    #+#             */
/*   Updated: 2023/06/07 22:38:37 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

typedef struct s_keys
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_keys;

typedef struct e_c
{
	int	e;
	int	c;
}	t_ec;

typedef struct mlx
{
	void	*mlx;
	void	*wind;
	t_keys	keys;
	char	**map;
	void	*wall;
	void	*exit;
	void	*floor;
	void	*player;
	void	*coins;
	t_ec	*ec;
	int		count;
}	t_mlx;

//libft
char	*ft_substr(char *s, size_t start, size_t end);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *src);
void	ft_swap(char *a, char *b);
char	*ft_itoa(int n);
void	ft_putstr(char *s);
//move_player
void	update_player(t_mlx *args);
//checks
void	check_name(char *str);
void	check_chars(char *s, t_ec *ec);
void	check_walls(char **map, int i, int y);
void	check_path(char **map, int j, int i, t_ec *ec);
//move_utils
int		key_press(int keycode, void *args);
int		key_release(int keycode, void *args);
void	get_image(t_mlx *args);
int		display(void *data);
//utils
char	*read_(int fd);
int		tab_size(char **map);
int		_close(void *args);
char	**array_dup(char **map);
void	_exit(int i);
//so_long
int		*find_p(char **map);

#endif