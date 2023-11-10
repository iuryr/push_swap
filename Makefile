NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
FLAGS = -Wall -Wextra -Werror

SRC = ./src/00_push_swap.c

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

LIBS = -L./libft -l:libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME) $(LIBS)

%.o : %.c
	$(CC) $(CFLAGS) -I. -I./include/ $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
