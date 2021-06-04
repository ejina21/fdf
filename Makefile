SRCS	=	$(wildcard *.c)

OBJS	=	$(SRCS:.c=.o)

NAME	=	fdf

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all:		make_libft $(NAME)

$(NAME):	$(OBJS) libft/libft.a libmlx.dylib
			$(CC) $(CFLAGS)  -o $@ $^

%.o:		%.c fdf.h libft/libft.h mlx.h
			$(CC) $(CFLAGS) -c $< -o $@

make_libft:
			@$(MAKE) -C libft/

clean:
			$(RM) $(OBJS)
			@$(MAKE) -C libft/ clean

fclean:		clean
			$(RM) $(NAME)
			@$(MAKE) -C libft/ fclean

re:			fclean all

.PHONY:		all make_libft clean fclean re