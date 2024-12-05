# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 12:57:14 by vgomes-p          #+#    #+#              #
#    Updated: 2024/12/05 18:09:46 by vgomes-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

SRCS := ft_strnstr.c \
		ft_strjoin.c \
		ft_split.c \
		ft_putstr_fd.c

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