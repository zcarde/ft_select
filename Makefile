# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/18 15:50:19 by zcarde            #+#    #+#              #
#    Updated: 2015/04/16 16:10:50 by zcarde           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRC = ft_select.c signal_catchers.c cursor.c init_struct.c keys.c keys2.c \
list_functions.c list_functions2.c prints.c term.c win_size.c

OBJ = $(SRC:.c=.o)

//FLAG = -Wall -Werror -Wextra -ggdb3

LIBFT = libft -lft -lncurses

INCLUDES = -I libft/includes

.PHONY : libft.a

all: libft.a  $(NAME)

libft.a:
	@$(MAKE) -C ./libft

$(NAME): $(OBJ) 
	gcc $(FLAG) $(OBJ) $(INCLUDES) -L$(LIBFT) -o $(NAME)

%.o: %.c
	gcc $(FLAG) $(INCLUDES) -c $^

clean :
	@make clean -C ./libft
	rm -f $(OBJ)

fclean : clean
	rm -f libft.a
	rm -f $(NAME)

re : fclean all
