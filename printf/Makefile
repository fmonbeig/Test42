# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 17:43:56 by fmonbeig          #+#    #+#              #
#    Updated: 2021/06/29 16:20:28 by fmonbeig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC =      gcc

CFLAG =   -Wall -Wextra -Werror

SRC_PATH=           src/

LIBFT_PATH=			libft/

INCLUDE_PATH=       include/

LIBFT_LIB=		libft.a

SRC =     src/printf_utils.c \
          src/ft_printf.c \
          src/output_character_and_pourcent.c \
          src/output_hexa.c \
          src/output_integer.c \
          src/output_pointer.c \
          src/output_string.c \
          src/output_unsigned.c \
          src/parsing_function.c \
          src/print_argument.c \
          src/print_argument2.c \
          src/printf_utils2.c \
          src/printf_utils3.c 
          
SRC_OBJ =           $(SRC:.c=.o)

LIBFT_OBJ=		${LIBFT_PATH}*.o

LIBFTMAKE=		$(MAKE) -C ${LIBFT_PATH}
	
all: $(NAME)

$(NAME): $(SRC_OBJ) lmake
	ar rcs $(NAME) $(SRC_OBJ) ${LIBFT_OBJ}

lmake:
		$(LIBFTMAKE)

clean:
				make -C ${LIBFT_PATH} clean
				${RM} ${SRC_OBJ}

fclean: 		clean
				rm -f ${NAME} ${LIBFT_PATH}${LIBFT_LIB}

re:         	fclean all

.PHONY:        all clean fclean re lmake
