# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/01 10:47:47 by apires-d          #+#    #+#              #
#    Updated: 2021/08/30 23:34:17 by apires-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang

FLAG = -Wall -Wextra -Werror

OBJ = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o	ft_isalpha.o \
	ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memccpy.o \
	ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o \
	ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o \
	ft_split.o ft_strchr.o ft_strdup.o ft_strjoin.o ft_strlcat.o \
	ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strncmp.o ft_strnstr.o \
	ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o \
	ft_len_nbr.o ft_len_uns_nbr.o ft_int_to_hex.o ft_putnbr_base.o \
	ft_strncpy.o get_next_line.o

OBJ_BONUS = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o \
	ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o \
	ft_lstmap.o

all: $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) *.o

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus: $(OBJ_BONUS) $(OBJ)
	ar -rcs $(NAME) *.o
