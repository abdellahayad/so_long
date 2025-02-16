# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aayad <aayad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 18:31:44 by aayad             #+#    #+#              #
#    Updated: 2025/02/16 08:45:47 by aayad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = so_long

FLAG = -Wall -Werror -Wextra

SRC = so_long.c flood_fill.c get_next_line.c help_to_move.c int_to_str.c move_player.c parssing_map.c\
procces_image.c split.c utils.c utils_2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c so_long.h
	$(CC) $(FLAG) -c $< -o $@
	ar rcs $(NAME) $@
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	

