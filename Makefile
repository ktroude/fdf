NAME = fdf

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = sources/main.c \
	   sources/get_next_line.c \
	   sources/get_next_line_utils.c \
	   sources/ft_split.c \
	   sources/ft_strlen.c \
	   sources/ft_strlcpy.c \
	   sources/ft_atoi.c \
	   sources/define_pt.c \
	   sources/brasenham.c \
	   sources/mapdata.c \
	   sources/event.c \
	   sources/get_tab.c \

INCLDIR = ./includes


OBJ = $(SRCS:.c=.o)

RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME) $(OBJB)

re : fclean all

.PHONY: all clean fclean re
