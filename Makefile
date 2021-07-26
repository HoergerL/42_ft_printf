NAME = libftprintf.a
FILES = 

BONUS = 
all: $(NAME)
$(NAME):
	gcc -Wall -Werror -Wextra $(FILES) -c 
	gcc -Wall -Werror -Wextra  -c 
	ar rc $(NAME) *.o ../*.o
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	gcc -Wall -Werror -Wextra $(BONUS) -c
	ar rc $(NAME) *.o

