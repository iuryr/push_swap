NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
FLAGS = -Wall -Wextra -Werror

SRC = ./src/00_push_swap.c \
	  ./src/01_input_processing.c \
	  ./src/02_llist_manipulation.c \
	  ./src/03_motions.c

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

debug: $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) -gdwarf-4 $(SRC) $(LIBFT_DIR)/*.c -o $(NAME) $(LIBS)


clean:
	rm -f src/*.o
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean $(NAME)

.PHONY: fclean clean all re
