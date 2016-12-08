# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/15 14:57:05 by eebersol          #+#    #+#              #
#    Updated: 2016/11/20 19:23:13 by eebersol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the program
NAME		=	fdf
LIB			=	./libft/libft.a
LIBX 		= -lm -I/usr/X11/include -L/usr/X11/lib -lX11 -lXext -lmlx
_SRC		=	main.c\
				parse_map.c\
				init.c\
				print_map\

INC			=	./includes/fdf.h \


SRC			=	$(addprefix srcs/,$(_SRC))
OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I./libft/ -I./includes/

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@make -C ./libft/
	@gcc $(CFLAGS)  -lm -L libft/ $(LIBX)  $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)
	@echo $(NAME) " - compiled"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@make clean -C libft
	@/bin/rm -rf $(OBJ)
	@echo $(NAME) " - Clean all .o files"

fclean: clean
	@make fclean -C libft
	@/bin/rm -rf $(NAME)
	@echo $(NAME) " - Clean executable"

re: fclean all

.PHONY: all, clean, fclean, re
