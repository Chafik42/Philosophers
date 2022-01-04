# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 15:26:40 by cmarouf           #+#    #+#              #
#    Updated: 2022/01/04 16:11:49 by cmarouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c \
	   srcs/error.c \
	   srcs/check_arguments.c \
	   utils/ft_atoi.c \

OBJS = ${SRCS:.c=.o}

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

THREADFLAGS = -pthread

NAME = philo

.c.o:
	${CC} -I includes ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(THREADFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
