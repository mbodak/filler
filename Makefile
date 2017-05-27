# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbodak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 16:40:31 by mbodak            #+#    #+#              #
#    Updated: 2017/04/03 19:56:36 by mbodak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= filler

GCC		= gcc

FLAG	= -Wall -Wextra -Werror

SRC		= parser.c put_shape.c strategy.c filler.c main.c

OBJ		= $(SRC:.c=.o)

LIB     = libft/

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	$(CC) $(CFLAGS) $(SRC) $(LIB)libft.a -o $(NAME)
	@printf "[CC] filler\n"

.c.o:
	@printf "[CC] %s\n" $<
	@$(CC) $(CFLAGS) -c $<  -o $@

clean:
	make -C $(LIB) clean
	$(RM) $(OBJ)

fclean : clean
		make fclean -C libft/
		rm -rf $(NAME)

re : 	fclean all
