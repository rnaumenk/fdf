# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/30 18:02:38 by rnaumenk          #+#    #+#              #
#    Updated: 2018/01/30 18:02:40 by rnaumenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIB = libft/libft.a
CS = 	./main.c \
		./key_hook.c \
		./calculation.c \
		./color.c \
		./errors.c \
		./mlx.c \
		./mouse.c \
		./other.c \
		./rendering.c \
		./rendering2.c 

all: $(NAME)

$(NAME): $(LIB) $(CS)
	@gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -o $@ $^
	@echo "\033[32mFDF IS READY\033[0m"

$(LIB):
	@cd libft && make && make clean

clean:
	@rm -f $(LIB)
	@echo "\033[36mLIBFT.A HAS BEEN DELETED\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mFDF HAS BEEN DELETED\033[0m"

re: fclean all

.PHONY: all clean fclean re