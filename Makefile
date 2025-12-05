# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/25 10:28:22 by hadrider          #+#    #+#              #
#    Updated: 2025/12/02 14:19:17 by hadrider         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar
ARFLAGS	= rcs
RM		= rm -f

SRC_DIR	= srcs
SRCS	= ft_printf.c \
		  $(SRC_DIR)/ft_putchar.c \
		  $(SRC_DIR)/ft_puthexlow.c \
		  $(SRC_DIR)/ft_puthexup.c \
		  $(SRC_DIR)/ft_putnbr.c \
		  $(SRC_DIR)/ft_putptr.c \
		  $(SRC_DIR)/ft_putstr.c \
		  $(SRC_DIR)/ft_putunsigned.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

.c.o: ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
