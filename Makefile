#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 11:58:02 by okryzhan          #+#    #+#              #
#    Updated: 2018/11/05 11:58:05 by okryzhan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRCS = main.c \
validation.c \
usage.c

OBJS = $(SRCS:.c=.o)

%.o: %.c fillit.h
	$(CC) $(FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) libft.a

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all