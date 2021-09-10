# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/01 10:47:47 by apires-d          #+#    #+#              #
#    Updated: 2021/09/09 21:45:18 by apires-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang

FLAG = -Wall -Wextra -Werror

OBJ = ft_atoi.o ft_bzero.o ft_calloc.o ft_itoa.o ft_memccpy.o \
	ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o \
	ft_strchr.o ft_strdup.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o \
	ft_strlen.o ft_strncmp.o ft_strnstr.o \
	ft_strrchr.o ft_strtrim.o ft_substr.o ft_len_nbr.o ft_strncpy.o \
	get_next_line.o ft_putchar_fd.o ft_putstr_fd.o \

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
