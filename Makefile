NAME		=	cub3D

header	=	cub3d.h

GLFW_LIB = $(shell brew --prefix glfw)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -Ofast -O3 -fsanitize=address -g

RM			=	rm -rf

SRCS		=	cub3d.c Map2D/map2d.c Map2D/set_window.c Map2D/set_player.c Chapes/rect.c Chapes/circle.c Chapes/line.c hooks/hooks.c hooks/key_A.c hooks/key_D.c\
				hooks/key_right.c hooks/key_left.c hooks/key_up.c hooks/key_down.c hooks/player_collision.c parsing.c utils.c main.c get_next_line.c ft_split.c\
				parsing2.c parsing3.c libft.c parsing4.c parsing5.c ft_split_set.c

OBJS		= $(SRCS:.c=.o)

$(NAME)		: $(OBJS) $(header)
			$(CC) $(CFLAGS)  ./libmlx/libmlx42.a -Iinclude -lglfw -L"$(GLFW_LIB)/lib/" $(OBJS) -o $(NAME)

%o:%c $(header)
	$(CC) $(CFLAGS) -c $< -o $@

all			:	$(NAME)

cm			:	all clean
	
clean		:
			$(RM) $(OBJS)

fclean		: clean
			$(RM) $(NAME)

re			: fclean all