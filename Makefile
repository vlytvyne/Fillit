#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 11:58:02 by okryzhan          #+#    #+#              #
#    Updated: 2018/11/06 12:31:22 by vlytvyne         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
CC = gcc
FLAGS =
SRCS = main.c \
validator.c \
utils.c \
marker.c \
extracter.c \
ruler.c \
sfillit.c \
sboard.c

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
