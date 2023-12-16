NAME		=	cub3D

header	=	cub3d.h

#GLFW_LIB = $(shell brew --prefix glfw)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -Ofast -O3 -fsanitize=address -g

RM			=	rm -rf

SRCS		=	cub3d.c Map2D/map2d.c Map2D/set_window.c Map2D/set_player.c Chapes/rect.c Chapes/circle.c Chapes/line.c hooks/hooks.c hooks/key_A.c hooks/key_D.c\
				hooks/key_right.c hooks/key_left.c hooks/key_up.c hooks/key_down.c hooks/player_collision.c\
				Parser/parsing.c Parser/utils.c Parser/main.c Parser/get_next_line.c Parser/ft_split.c Parser/parsing2.c Parser/parsing3.c Parser/libft.c Parser/parsing4.c Parser/parsing5.c Parser/ft_split_set.c\
				Ray_Casting/cast.c Ray_Casting/directions.c

OBJS		= $(SRCS:.c=.o)

#$(CC) $(CFLAGS)  ./libmlx/libmlx42.a -Iinclude -lglfw -L"$(GLFW_LIB)/lib/" $(OBJS) -o $(NAME)
$(NAME)		: $(OBJS) $(header)
			  $(CC) $(CFLAGS)  ./libmlx/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" $(OBJS) -o $(NAME)

%o:%c $(header)
	$(CC) $(CFLAGS) -c $< -o $@

all			:	$(NAME)

cm			:	all clean
	
clean		:
			$(RM) $(OBJS)

fclean		: clean
			$(RM) $(NAME)

re			: fclean all