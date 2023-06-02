/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:27:05 by yoelansa          #+#    #+#             */
/*   Updated: 2023/05/30 13:36:36 by yoelansa         ###   ########.fr       */
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
	int e;
	int c;
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
}	t_mlx;

//libft
char	*ft_substr(char *s, size_t start, size_t end);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *src);
void	ft_swap(char *a, char *b);
char	*ft_itoa(int n);
//
void	update_player(t_mlx *args);
int 	*find_p(char **map);
void	move_up(t_mlx *args, int dir);
//checks
void	check_name(char *str);
void	check_chars(char *s, t_ec *ec);
void	check_walls(char **map);
void	check_path(char **map, int j, int i, t_ec *ec);

#endif