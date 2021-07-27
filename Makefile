NAME = libftprintf.a
FILES = 

BONUS = 
all: $(NAME)
$(NAME):
	gcc -Wall -Werror -Wextra -C libft/*.c -c 
	gcc -Wall -Werror -Wextra  -c *.c
	ar rc $(NAME) *.o  libft/*.o
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	gcc -Wall -Werror -Wextra $(BONUS) -c
	ar rc $(NAME) *.o

