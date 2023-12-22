NAME		=	cub3D

header	=	cub3d.h


CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -Ofast -O3 -fsanitize=address -g

RM			=	rm -rf

SRCS		=	cub3d.c Map2D/map2d.c Map2D/set_window.c Map2D/set_player.c Chapes/rect.c Chapes/circle.c Chapes/line.c hooks/hooks.c hooks/esc.c hooks/left_right.c hooks/up_down.c hooks/rotation.c hooks/player_collision.c\
				Parser/parsing.c Parser/utils.c Parser/get_next_line.c Parser/ft_split.c Parser/parsing2.c Parser/parsing3.c Parser/libft.c Parser/parsing4.c Parser/parsing5.c Parser/ft_split_set.c\
				Ray_Casting/cast.c Ray_Casting/distance.c Ray_Casting/horizontal.c Ray_Casting/vertical.c Ray_Casting/directions.c Ray_Casting/normalize_angle.c Ray_Casting/wall_projection.c Parser/parse.c\
				textures/textures.c textures/check_textures.c
OBJS		= $(SRCS:.c=.o)


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