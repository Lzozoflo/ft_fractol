.PHONY: all clean fclean re f fclear c clear libmlx

NAME			=	fdfexec
cc				=	cc
FLAGS			=	-Wall -Wextra -Werror -MMD -MP
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

INC				=		ft_idk.h

SRC				=		main.c			\
						ft_close.c		\
						ft_key_press.c	\
						test.c

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
#										// COMPILATION										#
#																							#
#############################################################################################


all : libmlx $(NAME)


$(NAME)			:	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) $(MLX_FLAG) -o $(NAME)


$(D_OBJ)%.o		:	$(D_SRC)%.c Makefile $(INCS)
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@ -I $(D_INC) $(MLX_FLAG_I)


libmlx			:
			$(MAKE) -C minilibx-linux


#############################################################################################
#																							#
#								    // CLEAN  FCLEAN  RE									#
#																							#
#############################################################################################


clean 			:
			$(RM) $(D_OBJ)
			$(MAKE) -C minilibx-linux clean

fclean 			:	clean
			$(RM) $(NAME)

re 				:	 fclean all


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
