# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 06:38:26 by yoelansa          #+#    #+#              #
#    Updated: 2023/06/07 00:37:01 by yoelansa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long

CFLAGS= -Wall -Wextra -Werror #-fsanitize=address

SRC= libft/ft_strlen.c so_long.c libft/ft_strjoin.c libft/ft_split.c \
	libft/ft_strdup.c utils/move_player.c libft/ft_swap.c libft/ft_itoa.c \
	utils/checks.c utils/keys__textures.c utils/utils.c libft/ft_putstr.c

OBJ= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(OBJ) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all