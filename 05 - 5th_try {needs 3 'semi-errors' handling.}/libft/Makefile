# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgomes-p <vgomes-p@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 12:57:14 by vgomes-p          #+#    #+#              #
#    Updated: 2024/12/08 15:19:08 by vgomes-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

SRCS := ft_bzero.c ft_calloc.c ft_memset.c ft_strnstr.c \
	ft_strjoin.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
	ft_split.c ft_strchr.c ft_strdup.c ft_putstr_fd.c

OBJS := $(SRCS:.c=.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror
AR := ar -rcs
RM := rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re