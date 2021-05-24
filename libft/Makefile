# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 11:04:04 by fmonbeig          #+#    #+#              #
#    Updated: 2021/05/24 09:54:36 by fmonbeig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAG = -Wall -Werror -Wextra

SRC = ft_strlen.c \
ft_bzero.c \
ft_memcpy.c\
ft_memccpy.c\
ft_memmove.c\
ft_memchr.c \
ft_memcmp.c \
ft_strlen.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memset.c \
ft_tolower.c \
ft_toupper.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strtrim.c \
ft_strjoin.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \

BONUS = ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c 

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
	$(CC) $(FLAGS) -I includes -o $@ -c $<

clean: 
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
