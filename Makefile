# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 14:40:39 by cschulle          #+#    #+#              #
#    Updated: 2019/09/01 16:11:42 by cschulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	rainbowlines
SRCS	=	srcs/main.c			\
			srcs/images.c		\
			srcs/keycommands.c	\
			srcs/error.c
INCLS	=	includes/fractol.h
WFLAGS	=	-Wall -Wextra -Werror
MLXFLAGS=	-framework OpenGL -framework AppKit
LIBS	=	-L libft -lft -L mlx -L mlx -lmlx

GREY = \033[38;5;6m
BLUE = \033[38;5;37m
PURPLE = \033[38;5;99m
YELLOW = \033[38;5;214m
GREEN = \033[38;5;121m
WHITE = \033[0m

OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : 
	@echo "$(YELLOW)Libft:"
	@make -C ./libft/
	@echo "$(PURPLE)MLX:"
	@make -C ./mlx/
	@gcc  -o $(NAME) $(WFLAGS) $(MLXFLAGS) $(LIBS) $(SRCS)
	@echo "$(GREY)<< executable built >>$(WHITE)"

clean : 
	@rm -f $(OBJS)
	@echo "$(GREY)<< object files removed >>$(WHITE)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(GREY)<< executable removed >>$(WHITE)"	

re : fclean all

debug : 
	@gcc -g $(MLXFLAGS) $(SRCS) $(LIBS) -o DEBUGrainbows
	@echo "$(PURPLE)<< debug symbols compiled >>$(WHITE)"

fdebug : 
	@gcc -fsanitize=address -g $(MLXFLAGS) $(SRCS) $(LIBS) -o fsan_rainbows
	@echo "$(PURPLE)<< debug symbols compiled >>$(WHITE)"
	@echo "$(PURPLE)<< fsanitize enabled >>$(WHITE)"

leakcheck : 
	@clang -fsanitize=address -fno-omit-frame-pointer -g $(MLXFLAGS) $(SRCS) $(LIBS) -o leak_rainbows
	@echo "$(GREEN)<< debug symbols compiled >>$(WHITE)"
	@echo "$(GREEN)<< fsanitize leak check enabled >>$(WHITE)"

debugclean :
	@rm -rf DEBUGrainbows.dSYM
	@rm DEBUGrainbows
	@rm -rf fsan_rainbows.dSYM
	@rm fsan_rainbows
	@rm -rf leak_rainbows.dSYM
	@rm leak_rainbows
	@echo "$(PURPLE)<< debug files removed>>$(WHITE)"
