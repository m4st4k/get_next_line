# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbriant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 20:06:56 by dbriant           #+#    #+#              #
#    Updated: 2025/04/07 21:26:27 by dbriant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= test
CC	= cc
CFLAGS	= -Werror -Wextra -Wall -D BUFFER_SIZE=42
DELALL	= *.o
SRCS    = get_next_line.c get_next_line_utils.c
OBJS    = $(SRCS:.c=.o)

all : $(NAME)
$(NAME) : $(OBJS)
	$(MAKE) *.o
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
fclean:
	-rm -f $(DELALL) *.o
clean:
	-rm -f $(DELALL) *.o
re: fclean all
.PHONY: clean fclean all re
