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

# path and files
H_SRCS		=	pipex.h
H_DIR		=	includes/
HEADER		=	$(addprefix $(H_DIR), $(H_SRCS))

MAPA_SRCS	=	pipex.c ppx_processes.c ppx_path.c ppx_utils.c
MAPA_DIR	=	pipexcodes/
OBJ_DIR		=	build/
OBJ_M		=	$(addprefix $(OBJ_DIR), $(notdir $(MAPA:.c=.o)))

MAPA		=	$(addprefix $(MAPA_DIR), $(MAPA_SRCS))

LIBFT_DIR	=	libft/
LIBFT		=	$(LIBFT_DIR)libft.a

# Rules
$(OBJ_DIR)%.o: $(MAPA_DIR)%.c $(HEADER)
			@mkdir -p $(OBJ_DIR)
			$(CC) $(FLAGS) -c $< -o $@
			

$(NAME): $(OBJ_M) $(LIBFT)
			$(CC) $(FLAGS) $(OBJ_M) $(LIBFT) -o $(NAME)
			@echo -e "$(GREEN)execution completed $(NAME) created!$(DEFAULT)"

$(LIBFT):
			@make -C $(LIBFT_DIR)

all:		$(NAME)

clean:
			@$(RM) $(OBJ_M)
			@make clean -C $(LIBFT_DIR)
			@echo -e "$(YELLOW)execution completed!$(DEFAULT)"

fclean: clean
			@$(RM) $(NAME)
			@make fclean -C $(LIBFT_DIR)
			@echo -e "$(RED)all execution completed!$(DEFAULT)"

re:			fclean all

.PHONY:		all clean fclean re

RED  = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m