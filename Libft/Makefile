# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grivault <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 11:06:44 by grivault          #+#    #+#              #
#    Updated: 2025/11/24 11:19:19 by grivault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_LST = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
          ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

SRC_MEM = ft_memmove.c ft_memset.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		  ft_bzero.c ft_calloc.c 

SRC_MISC = ft_atoi.c ft_atoi_safe.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		   ft_isdigit.c ft_isprint.c ft_itoa.c get_next_line.c ft_tablen.c 

SRC_PRINT = ft_putendl_fd.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_printf.c puterror.c exit_error.c

SRC_PRINTF = checks.c data_init.c ft_putchar_data.c ft_putx_data.c \
			 ft_putxup_data.c ft_putnbr_data.c ft_putstr_data.c ft_putpercent_data.c \
			 ft_putptr_data.c ft_putud_data.c

SRC_STR = ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
		  ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
		  ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
		  ft_toupper.c free_strings.c

SRC = $(addprefix List/, $(SRC_LIST)) \
	  $(addprefix Memory/, $(SRC_MEM)) \
	  $(addprefix Miscellaneous/, $(SRC_MISC)) \
	  $(addprefix Print/, $(SRC_PRINT) $(addprefix Printf_utils/, $(SRC_PRINTF))) \
	  $(addprefix String/, $(SRC_STR))

OBJ = $(SRC:.c=.o)

INCLUDES = -I . -I Print/Printf_utils/.

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

redo: re
	make clean
	clear

.PHONY: all clean fclean re bonus
