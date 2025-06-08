# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 11:08:24 by marvin            #+#    #+#              #
#    Updated: 2025/01/21 11:08:24 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = ./libft/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f

SRC = ./src/push_swap.c  ./src/ft_parse.c ./src/ft_error.c 
OBJ = $(SRC:.c=.o)

all: ${MLX} ${LIBFT} ${NAME}

${NAME}: ${OBJ}
			${CC} ${SRC} ${MLX} ${LIBFT} ${CFLAGS} ${MINILIBX_FLAGS} -o ${NAME}

${LIBFT}:
			make -C libft/

bonus: ${OBJ}
			${CC} ${SRC} ${MLX} ${LIBFT} ${CFLAGS} ${MINILIBX_FLAGS} -o ${NAME}

clean: 
			make clean -C libft/
					${RM} ${OBJ}

fclean: clean
			${RM} ${NAME}
					make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
