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
FLAGS = -Wall -Werror -Wextra
SRCS = main.c \
validator.c \
utils.c \
marker.c \
extracter.c \
ruler.c \
sfillit.c \
sboard.c \
ft_strnew.c \
ft_strlen.c \
ft_putstr.c \
ft_putendl.c \
ft_putchar.c \
get_next_line.c \
ft_putchar_fd.c \
ft_strdup.c \
ft_strjoin.c \
ft_strrchr.c \
ft_strsub.c \
ft_strcat.c \
ft_strcpy.c \
ft_strdel.c \
ft_strncpy.c

OBJS = $(SRCS:.c=.o)

%.o: %.c fillit.h
	$(CC) $(FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

git: fclean
	git add .
	git commit
	git push
