# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 14:34:47 by vgomes-p          #+#    #+#              #
#    Updated: 2024/12/04 14:34:47 by vgomes-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -I $(H_DIR) -I $(LIBFT_DIR)
RM			=	rm -rf

# Caminhos e arquivos
H_SRCS		=	pipex.h
H_DIR		=	includes/
HEADER		=	$(addprefix $(H_DIR), $(H_SRCS))

MAPA_SRCS	=	pipex.c ppx_utils.c
MAPA_DIR	=	pipexcodes/
MAPA		=	$(addprefix $(MAPA_DIR), $(MAPA_SRCS))
OBJ_M		=	$(MAPA:.c=.o)

LIBFT_DIR	=	libftplus/
LIBFT		=	$(LIBFT_DIR)libft.a

# Regras de compilação
%.o: %.c $(HEADER) Makefile
			$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_M) $(LIBFT)
			$(CC) $(FLAGS) $(OBJ_M) $(LIBFT) -o $(NAME)
			@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

$(LIBFT):
			@make -C $(LIBFT_DIR)

all:		$(NAME)

clean:
			@$(RM) $(OBJ_M)
			@make clean -C $(LIBFT_DIR)
			@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean: clean
			@$(RM) $(NAME)
			@make fclean -C $(LIBFT_DIR)
			@echo -e "$(RED)all deleted!$(DEFAULT)"

re:			fclean all

.PHONY:		all clean fclean re

RED  = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m