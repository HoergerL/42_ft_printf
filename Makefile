CC = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = *.c

LIBFT_PATH = ./libft/

MAKE = make

all: sub_libft $(NAME)


$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar -rcs $(NAME) *.o $(LIBFT_PATH)*.o

sub_libft:
	$(MAKE) LIBFT.a -C $(LIBFT_PATH)

clean:
	rm -f *.out
	rm -f *.o
	$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all