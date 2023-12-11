# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 15:46:40 by araji-af          #+#    #+#              #
#    Updated: 2023/12/11 17:12:59 by araji-af         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

header	=	cub3d.h

CC			=	cc

CFLAGS		=	 -Wall -Wextra -Werror

RM			=	rm -rf

SRCS		=	parsing.c utils.c main.c get_next_line.c ft_split.c parsing2.c parsing3.c libft.c parsing4.c parsing5.c ft_split_set.c

OBJS		= $(SRCS:.c=.o)

$(NAME)		: $(OBJS) $(header)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%o:%c $(header)
	$(CC) $(CFLAGS)  -c $< -o $@

all			:	$(NAME)

f		:	all clean

clean		:
			$(RM) $(OBJS)

fclean		: clean
			$(RM) $(NAME)

re			: fclean all