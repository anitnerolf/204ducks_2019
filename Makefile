##
## EPITECH PROJECT, 2020
## 204ducks
## File description:
## makefile
##

SRC	=	src/main.cpp	\
		src/Ducks.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	204ducks

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME) message

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CFLAGS) -lm -I ./include

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f *~ $(NAME)

re:		fclean all

message:
		@echo "Successfully compiled!"
