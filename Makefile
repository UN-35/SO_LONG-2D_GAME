# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 06:38:26 by yoelansa          #+#    #+#              #
#    Updated: 2023/05/15 19:41:33 by yoelansa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long

CFLAGS= -Wall -Wextra -Werror #-fsanitize=address

SRC= libft/ft_strlen.c so_long.c libft/ft_strjoin.c libft/ft_split.c

OBJ= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(OBJ) $(CFLAGS) -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all