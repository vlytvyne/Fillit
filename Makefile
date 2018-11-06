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
SRCS = tmain.c \
validator.c \
sboard.c \
sfillit.c

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

git: fclean
	git add .
	git commit
	git push