.PHONY: all clean fclean re f fclear c clear libmlx libft

NAME			=	fdfexec
cc				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD -MP -O3
CFLAGS_MORE		=	-Weverything -Wpadded
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



#############################################################################################
#																							#
#										// SOURCE											#
#																							#
#############################################################################################

INC				=		ft_fractol.h

SRC				=		main.c			\
						ft_close.c		\
						ft_key_press.c	\
ft_mandelbrot.c
# test.c

NAME_LIBMLX		=		./minilibx-linux/libmlx_Linux.a
MLX_FLAG		=		-Lminilibx-linux -lmlx -lX11 -lXext -lbsd -lm
MLX_FLAG_I		=		-Imlx_linux -Iminilibx-linux

#############################################################################################
#																							#
#										// OBJECT											#
#																							#
#############################################################################################


# All src in his Src Directories
SRCS			=		$(addprefix $(D_SRC), $(SRC))


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
			$(CC) $(FLAGS) $(OBJS) $(MLX_FLAG) $(NAME_LIB) -o $(NAME)


$(D_OBJ)%.o		:	$(D_SRC)%.c Makefile $(INCS)
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@ -I $(D_INC) $(MLX_FLAG_I) -I $(D_INC_LIBFT)


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


#to see what variables did
debug			:
	@echo "Debug: $(all)"
 -include $(DEPS)
