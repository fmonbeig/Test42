# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 17:43:56 by fmonbeig          #+#    #+#              #
#    Updated: 2021/06/03 15:25:46 by fmonbeig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAG = -Wall -Wextra -Werror

SRC = ft_strlen.c \
ft_bzero.c \

BONUS = ft_lstnew.c \
ft_lstadd_front.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS=	$(BONUS:.c=.o)

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)
	ranlib $(NAME)

bonus:		$(OBJ) $(OBJ_BONUS)
			@ar rc $(NAME) $^
			@echo "$(NAME) created with bonus"
			@ranlib $(NAME)
			@echo "$(NAME) indexed with bonus"
			
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -I includes -o $@ -c $<

clean: 
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

- Essayer de faire son makefile qui compile avec la librairie

(4) USE the library in other programs:
    step 1: Add an include line (#include "mylib.h") in all program source files that use library definitions (e.g., test.c).

    step 2: Link the program's .c file with the library object file 
            (i.e. specify the mylib.o file as a command line argument to gcc): 

             gcc  test.c mylib.o

        OR to link in libmylib.so (or libmylib.a):

             gcc  test.c -lmylib

        OR to link with a library not in the standard path:

             gcc  test.c -L/home/newhall/lib -lmylib

        The resulting a.out out will contain machine code for all the functions 
        defined in test.c plus any mylib library functions that are called by 
        the test.c code. 


		Include the library headers in (your) files.
Then while building your executable, add the location of the library's header files to your compiler's include path and then link against the static library. As in

gcc -I/Directory path where mylib header files are located/ foo.c bar.c /Directory where mylib archive is located/mylib.a

Here foo.c and bar.c are files containing your code.