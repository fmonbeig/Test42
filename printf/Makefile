# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 17:43:56 by fmonbeig          #+#    #+#              #
#    Updated: 2021/06/02 17:44:58 by fmonbeig         ###   ########.fr        #
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
