.PHONY: all clean fclean re f fclear c clear libmlx libft

NAME			=	fractol
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD -MP -Ofast
CFLAGSS			=	-Weverything -Wno-padded
RM				=	rm -fr


#############################################################################################
#																							#
#										// Directories										#
#																							#
#############################################################################################


# Directories
D_SRC			=		src/
D_OBJ			=		object/
D_INC			=		inc/

# Source Directories
D_EVENT			=		event/
D_FRACTAL		=		fractal/


#############################################################################################
#																							#
#										// SOURCE											#
#																							#
#############################################################################################


INC				=		ft_fractol.h

SRC				=		main.c				\
						ft_close.c			\
						ft_init.c			\
						ft_param.c

SRC_EVENT		=		ft_is_keycode.c		\
						ft_julia_event.c	\
						ft_key_event.c		\
						ft_mouse_event.c

SRC_FRACTAL		=		ft_burning_ship.c	\
						ft_draw.c			\
						ft_mandelbrot.c		\
						ft_julia.c


MLX_FLAG		=		-Lminilibx-linux -lmlx -lX11 -lXext
MLX_FLAG_I		=		-Iminilibx-linux


#############################################################################################
#																							#
#										// OBJECT											#
#																							#
#############################################################################################


# All src in his Src Directories
SRCS			=		$(addprefix $(D_SRC), $(SRC))						\
						$(addprefix $(D_SRC)$(D_EVENT), $(SRC_EVENT))		\
						$(addprefix $(D_SRC)$(D_FRACTAL), $(SRC_FRACTAL))

# Changing all source directories to object directories
OBJS			=		$(subst $(D_SRC), $(D_OBJ), $(SRCS:.c=.o))
D_OBJS			=		$(subst $(D_SRC), $(D_OBJ), $(SRCS))
DEPS			=		$(SRCS:%.c=%.d)

INCS			=		$(addprefix $(D_INC), $(INC))


#############################################################################################
#																							#
#										// LIBFT											#
#																							#
#############################################################################################


D_INC_LIBFT		=		./libft/inc/


NAME_LIB		=		./libft/libft.a


#############################################################################################
#																							#
#										// COMPILATION										#
#																							#
#############################################################################################


all : libmlx libft $(NAME)


$(NAME)			:	$(OBJS)
			$(CC) $(CFLAGSS) $(OBJS) $(MLX_FLAG) $(NAME_LIB) -o $(NAME)

$(D_OBJ)%.o		:	$(D_SRC)%.c Makefile $(INCS) $(NAME_LIB)
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGSS) -c $< -o $@ -I $(D_INC) $(MLX_FLAG_I) -I $(D_INC_LIBFT)

libmlx			:
			$(MAKE) -C minilibx-linux

libft			:
			$(MAKE) -C libft


#############################################################################################
#																							#
#								    // CLEAN  FCLEAN  RE									#
#																							#
#############################################################################################


clean			:
			$(RM) $(D_OBJ)
			$(MAKE) -C minilibx-linux clean
			$(MAKE) -C libft clean


fclean			:
			$(RM) $(D_OBJ)
			$(RM) $(NAME)
			$(MAKE) -C minilibx-linux clean
			$(MAKE) -C libft fclean

re				:	 fclean all


#############################################################################################
#																							#
#										Allias									#
#																							#
#############################################################################################


c				:	clear
clear			:	clean

f				:	fclean
fclear			:	fclean


 -include $(DEPS)
